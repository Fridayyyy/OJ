//
// Created by 86184 on 2022/10/8.
//
#include <iostream>


using namespace std;

class Node{
public:
    char data;
    Node *left;
    Node *right;
    Node():left(nullptr),right(nullptr){}
};

class Tree{
private:
    int pos;
    Node *root;
    string strTree;
    Node* createTree();
    void mirror(Node* root);
public:
    Tree();
    ~Tree();
    void createTree(string str);
    void mirror();
};
Tree::Tree() {

}
Tree::~Tree() {

}
void Tree::createTree(string str) {
    pos=0;
    strTree.assign(str);
    root=createTree();
}

Node *Tree::createTree() {
    Node* T;
    char ch;
    ch=strTree[pos++];
    if (ch=='#'){
        T= nullptr;
    } else{
        T=new Node;
        T->data=ch;
        T->left=createTree();
        T->right=createTree();
    }
    return T;
}

void Tree::mirror() {
    mirror(root);
}

void Tree::mirror(Node *node) {

}


int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {

    }
}