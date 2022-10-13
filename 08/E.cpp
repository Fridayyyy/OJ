//
// Created by 86184 on 2022/10/13.
//
#include <iostream>
#include <queue>
using namespace std;

class Node{
public:
    char data;
    Node* left;
    Node* right;

    Node(){
        left= nullptr;
        right= nullptr;
    }
    ~Node(){

    }
};

class Tree{
    Node* root;
    int pos;
    string strTree;

    Node* createTree();
    pair<int,Node*> getDepth(Node* node);
    void getMaxLength(Node *node);
public:
    Tree(){
        maxLength=0;
        node1= nullptr;
        node2= nullptr;
    }
    ~Tree(){

    }
    int maxLength;
    Node* node1;
    Node* node2;
    void getMaxLength();
    void createTree(const string& str);

};

void Tree::getMaxLength(Node *node) {
    if (!node){
        return;
    }
    int leftHeight=0,rightHeight=0;
    if (node->left){
        leftHeight= getDepth(node->left).first;
    }
    if (node->right){
        rightHeight= getDepth(node->right).first;
    }
    if (maxLength<(leftHeight+rightHeight)){
        maxLength=leftHeight+rightHeight;
        if (getDepth(node->left).second){
            node1=getDepth(node->left).second;
        }
        if (getDepth(node->right).second){
            node2=getDepth(node->right).second;
        }
    }
    getMaxLength(node->left);
    getMaxLength(node->right);
}

void Tree::getMaxLength() {
    getMaxLength(root);
}

void Tree::createTree(const string& str) {
    pos=0;
    strTree.assign(str);
    root=createTree();
    node1=root;
    node2=root;
}

Node *Tree::createTree() {
    Node* T;
    char ch=strTree[pos++];
    if (ch=='#')
        return nullptr;
    else{
        T=new Node;
        T->data=ch;
        T->left=createTree();
        T->right=createTree();
    }
    return T;
}

pair<int,Node*> Tree::getDepth(Node *node) {
    if (!node){
        return make_pair(0, nullptr);
    }
    int depth=0;
    Node* last= nullptr;
    queue<Node*> que;
    que.push(node);
    while (!que.empty()){
        int size=que.size();
        for (int i = 0; i < size; ++i) {
            Node* temp=que.front();
            last=temp;
            que.pop();
            if (temp->left){
                que.push(temp->left);
            }
            if (temp->right){
                que.push(temp->right);
            }
        }
        depth++;
    }
    return make_pair(depth,last);
}


int main(){
    int n;
    cin>>n;
    while (n--){
        string str;
        cin>>str;
        Tree t;
        t.createTree(str);
        t.getMaxLength();

        cout<<t.maxLength<<":";
        if (t.maxLength!=0){
            cout<<t.node1->data<<" "<<t.node2->data;
        }
        cout<<endl;
    }
}