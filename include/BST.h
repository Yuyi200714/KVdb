#pragma once
#include<iostream>
#include<string>
using namespace std;
struct BSTNode
{
    BSTNode(const string& key = string(), const string& value = string())
        : _pLeft(nullptr), _pRight(nullptr), _key(key), _value(value)
    {}
    BSTNode* _pLeft;
    BSTNode* _pRight;
    string _key;
    string _value;
};
class BST
{
    typedef BSTNode Node;
private:
    Node* _root = nullptr;
public:
    void Insert(const string& key, const string& value);
    Node* Find(const string& key);
    bool Erase(const string& key);
    void _InOrder(Node* root);
    void InOrder();
    void _deleteNode(Node* root);
    Node* _getRoot();
    ~BST();
};
