#include<KVDB.h>
KVDB::KVDB(string name){
    filename = name;
    this->bst = new BST();
}
KVDB::~KVDB(){
    delete this->bst;
}
void KVDB::put(string key, string value){
    this->bst->Insert(key, value);
}
string KVDB::get(string key){
    return this->bst->Find(key)->_value;
}