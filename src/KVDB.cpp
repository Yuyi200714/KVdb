#include<KVDB.h>
#include<string>
#include<fstream>
void KVDB::loadFromFile(){
    std::ifstream file;
    file.open(this->filename);
    if(!file){
        return;
    }
    string key, value;
    while(file >> key >> value){
        this->bst->Insert(key, value);
    }
    file.close();
    std::ifstream logFile;
    logFile.open(this->logFilename);
    if(!logFile){
        return;
    }
    string op, key2, value2;
    while(logFile >> op >> key2){
        if(op == "put"){
            logFile >> value2;
            this->bst->Insert(key2, value2);
        }else if(op == "del"){
            this->bst->Erase(key2);
        }
    }
    logFile.close();
}

void KVDB::saveToFile(){
    std::ofstream file;
    file.open(this->filename, std::ios::out|std::ios::trunc);
    if(!file){
        return;
    }
    this->saveNodeToFile(this->bst->_getRoot());
    file.close();
}

void KVDB::saveNodeToFile(Node *node){
    if(node == NULL){
        return;
    }
    this->saveNodeToFile(node->_pLeft);
    std::ofstream file;
    file.open(this->filename, std::ios::app);
    if(!file){
        return;
    }
    file << node->_key << " " << node->_value << std::endl;
    file.close();
    this->saveNodeToFile(node->_pRight);
}

KVDB::KVDB(string filename, string logFilename){
    this->filename =filename;
    this->logFilename = logFilename;
    this->bst = new BST();
    this->loadFromFile();

}
KVDB::~KVDB(){
    this->saveToFile();
    if(std::remove(this->logFilename.c_str()) != 0){
        std::cout << "Error deleting file" << std::endl;
    }
    else{
        std::cout << "logFile successfully deleted" << std::endl;
    }
    delete this->bst;
}
void KVDB::put(string key, string value){
    std::ofstream logFile;
    logFile.open(this->logFilename, std::ios::out | std::ios::app);
    if(logFile.fail()){
        std::perror(("Error opening file: " + this->logFilename).c_str());
        exit(0);
    }
    logFile << "put " << key << " " << value << std::endl;
    logFile.close();
    this->bst->Insert(key, value);
}
void KVDB::del(string key){
    std::ofstream logFile;
    logFile.open(this->logFilename, std::ios::out | std::ios::app);
    logFile << "del " << key << std::endl;
    logFile.close();
    this->bst->Erase(key);
}
string KVDB::get(string key){
    Node *node = this->bst->Find(key);
    if(node == nullptr){
        return "";
    }
    return node->_value;
}