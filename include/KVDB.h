#pragma once
#include<BST.h>
#include<string>
using namespace std;
class KVDB{
    typedef BSTNode Node;
    private:
        BST *bst;
        string filename = "test.db";
        string logFilename = "log.txt";
        void loadFromFile();
        void saveToFile();
        void saveNodeToFile(Node *node);
    public:
        KVDB(string filename = "test.db",string logFilename = "log.txt");
        ~KVDB();
        void put(string key, string value);
        void del(string key);
        string get(string key);

};