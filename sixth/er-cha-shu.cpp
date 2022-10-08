//
// Created by 86184 on 2022/9/29.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class BiTreeNode{
public:
    char data;
    BiTreeNode* leftChild;
    BiTreeNode* rightChild;
    BiTreeNode():leftChild(nullptr),rightChild(nullptr){}
    ~BiTreeNode();
};

class BiTree{
private:
    BiTreeNode* root;
    int pos;
    string strTree;
    BiTreeNode* CreateBiTree();
    void PreOrder(BiTreeNode* t);
    void InOrder(BiTreeNode* t);
    void PostOrder(BiTreeNode* t);
public:
    BiTree();
    ~BiTree();
    void CreateTree(string treeArray);
    void PreOrder();
    void InOrder();
    void PostOrder();
};
BiTree::BiTree() {

}
BiTree::~BiTree(){

}

void BiTree::CreateTree(std::string treeArray) {
    pos=0;
    strTree.assign(treeArray);
    root=CreateBiTree();
}

BiTreeNode *BiTree::CreateBiTree() {
    BiTreeNode* T;
    char ch;
    ch=strTree[pos++];
    if (ch=='0')
        T= nullptr;
    else{
        T=new BiTreeNode();
        T->data=ch;
        T->leftChild=CreateBiTree();
        T->rightChild=CreateBiTree();
    }

    return T;
}
void BiTree::PreOrder() {
    PreOrder(root);
}

void BiTree::PreOrder(BiTreeNode *t) {
    if (t== nullptr)
        return;
    cout<<t->data;
    PreOrder(t->leftChild);
    PreOrder(t->rightChild);
}

void BiTree::InOrder() {
    InOrder(root);
}

void BiTree::InOrder(BiTreeNode *t) {
    if (t== nullptr)
        return;
    InOrder(t->leftChild);
    cout<<t->data;
    InOrder(t->rightChild);

}

void BiTree::PostOrder(){
    PostOrder(root);
}

void BiTree::PostOrder(BiTreeNode *t)  {
    if (t== nullptr)
        return;
    PostOrder(t->leftChild);
    PostOrder(t->rightChild);
    cout<<t->data;

}


int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin>>str;
        BiTree *tree=new BiTree;
        tree->CreateTree(str);
        tree->PreOrder();
        cout<<endl;
        tree->InOrder();
        cout<<endl;
        tree->PostOrder();
        cout<<endl;
    }
}
