#pragma once
#include<BST.h>
#include<string>
using namespace std;
class KVDB{
    typedef BSTNode Node;
    private:
        BST *bst;
        string filename;
        void loadFromFile();
        void saveToFile();
        void saveNodeToFile(Node *node);
    public:
        KVDB(string name);
        ~KVDB();
        void put(string key, string value);
        string get(string key);
};