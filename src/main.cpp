#include<stdio.h>
#include<stdlib.h>
#include<BST.h>
#include<KVDB.h>
#include<string>
#include<iostream>
int main(){
    KVDB *kvdb = new KVDB("test.db");
    kvdb->put("hello", "world");
    std::cout << kvdb->get("hello") << std::endl;
}