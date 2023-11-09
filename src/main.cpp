#include<stdio.h>
#include<stdlib.h>
#include<BST.h>
#include<string>
#include<iostream>
int main(){
    BST bst;
    bst.Insert("hello","Zhang");
    bst.Insert("world","Yu");
    bst.InOrder();
}