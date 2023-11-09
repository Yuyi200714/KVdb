#pragma once
#include<BST.h>
#include<string>
using namespace std;
class KVDB{
    private:
        BST *bst;
        string filename;
    public:
        KVDB(string name);
        ~KVDB();
        void put(string key, string value);
        string get(string key);
};