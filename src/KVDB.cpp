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
}

void KVDB::saveToFile(){
    std::ofstream file;
    file.open(this->filename);
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

KVDB::KVDB(string name){
    filename = name;
    this->bst = new BST();
    this->loadFromFile();
}
KVDB::~KVDB(){
    this->saveToFile();
    delete this->bst;
}
void KVDB::put(string key, string value){
    this->bst->Insert(key, value);
}
string KVDB::get(string key){
    return this->bst->Find(key)->_value;
}