#include <iostream>

class Node{
public:
    char data;
    Node *left;
    Node *right;
    Node(char d){
        data=d;
        left=right= nullptr;
    }
};

class Tree{
    Node *root;
    Tree(){

    }
    void insert(char data){

    }
};