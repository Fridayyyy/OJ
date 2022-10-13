//
// Created by 86184 on 2022/10/12.
//
#include <iostream>
#include <vector>

using namespace std;

class Node{
public:
    Node* left;
    Node* right;
    char data;
    Node(){
        data=0;
        left= nullptr;
        right= nullptr;
    }
};

class Tree{
private:
    string strTree;
    Node* createTree(int pos);
public:
    Node* root;
    void createTree(string str);
    void display(Node *node);
};

void Tree::createTree(std::string str) {
    strTree.assign(str);
    root=createTree(0);
}

Node *Tree::createTree(int pos) {
    Node *T;
    char ch;
    if (pos>=strTree.length())
        return nullptr;
    ch=strTree[pos];
    if (ch=='0'){
        T= nullptr;
    } else{
        T=new Node();
        T->data=ch;
        T->left= createTree(pos*2+1);
        T->right= createTree(pos*2+2);
    }
    pos++;
    return T;
}

void Tree::display(Node *node) {
    if (node){
        cout<<node->data;
        display(node->left);
        display(node->right);
    }
}


int main(){
    int n;
    cin>>n;
    while (n--){
        string str;
        cin>>str;

        Tree t;
        t.createTree(str);
        t.display(t.root);
        cout<<endl;
    }
}