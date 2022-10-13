//
// Created by 86184 on 2022/10/13.
//
#include <iostream>
#include <queue>
#include <string>

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

    Node* createTree();
    Node* root;
    string strTree;
    int pos;
    void getDepth(Node* node);

public:
    int maxDepth;
    Tree(){
        maxDepth=0;
    }
    ~Tree(){

    }
    void createTree(string str);
    void getDepth();
};

void Tree::createTree(std::string str) {
    strTree.assign(str);
    pos=0;
    root=createTree();
}

Node *Tree::createTree() {
    Node* T;
    char ch=strTree[pos++];
    if (ch=='0'){
        return nullptr;
    } else{
        T=new Node;
        T->data=ch;
        T->left=createTree();
        T->right=createTree();
    }
    return T;
}

void Tree::getDepth() {
    getDepth(root);
}

void Tree::getDepth(Node *node) {
    queue<Node*> que;
    que.push(node);
    while (!que.empty()){
        int size=que.size();
        for (int i = 0; i < size; ++i) {
            Node* temp=que.front();
            que.pop();
            if (temp->left){
                que.push(temp->left);
            }
            if (temp->right){
                que.push(temp->right);
            }
        }
        maxDepth++;
    }
}

using namespace std;
int main(){
    int n;
    cin>>n;
    while (n--){
        string str;
        cin>>str;
        Tree t;
        t.createTree(str);
        t.getDepth();
        cout<<t.maxDepth<<endl;
    }
}