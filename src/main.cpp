#include<stdio.h>
#include<stdlib.h>
#include<BST.h>
#include<KVDB.h>
#include<string>
#include<iostream>
#include<fstream>
int main(){
    KVDB *kvdb = new KVDB("/mnt/md0/testdb/test.db", "/mnt/md0/testdb/log.txt");
    kvdb->put("hello", "world");
    kvdb->put("hello2", "world2");
    kvdb->put("hello3", "world3");
    string value = kvdb->get("hello");
    if(value.size()){
        std::cout << "key hello have value:"<< value<< std::endl;
    }
    kvdb->del("hello");
    //exit(0);
    value = kvdb->get("hello");
    if(!value.size()){
        std::cout << "key hello have no value" << std::endl;
    }
    kvdb->del("hello2");
    delete kvdb;
    return 0;
}