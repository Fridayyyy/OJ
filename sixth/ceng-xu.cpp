//
// Created by 86184 on 2022/9/29.
//
#include <string>
#include <vector>
#include <queue>
#include <iostream>

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
    void BFS(BiTreeNode* t);

public:
    BiTree();
    ~BiTree();
    void CreateTree(string treeArray);
    void BFS();
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

void BiTree::BFS() {
    BFS(root);
}

void BiTree::BFS(BiTreeNode* t) {
    queue<BiTreeNode*> que;
    que.push(t);
    while (!que.empty()){
        BiTreeNode* temp=que.front();
        cout<<que.front()->data;
        que.pop();
        if (temp->leftChild){
            que.push(temp->leftChild);
        }
        if (temp->rightChild){
            que.push(temp->rightChild);
        }
    }
}

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin>>str;
        BiTree* tree=new BiTree;
        tree->CreateTree(str);
        tree->BFS();
        cout<<endl;
    }
}
