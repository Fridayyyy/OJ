//
// Created by 86184 on 2022/9/29.
//
#include <string>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>

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
    void Post(BiTreeNode* t);

public:
    BiTree();
    ~BiTree();
    void CreateTree(string treeArray);
    void Post();
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

void BiTree::Post() {
    Post(root);
}

void BiTree::Post(BiTreeNode *t) {
    stack<BiTreeNode*> stk;
    stk.push(root);
    vector<char> vec;
    while (!stk.empty()){
        BiTreeNode* temp=stk.top();
        vec.push_back(temp->data);
        stk.pop();
        if (temp->leftChild) stk.push(temp->leftChild);
        if (temp->rightChild) stk.push(temp->rightChild);
    }
    reverse(vec.begin(),vec.end());
    for (auto c:vec) {
        cout<<c;
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
        tree->Post();
        cout<<endl;
    }
}