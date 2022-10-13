//
// Created by 86184 on 2022/10/12.
//
#include <iostream>
#include <vector>

using namespace std;
class Node{
public:
    int data;
    Node* right;
    Node* left;
    Node(){
        data=0;
        left= nullptr;
        right= nullptr;
    }
    ~Node(){
        data=0;
        delete left;
        delete right;
        left= nullptr;
        right= nullptr;
    }
};

class Tree{
public:
    Node* root;
    int *inOrder;
    int *postOrder;
    int len;
    int Min;

    Node* create(int left,int right,int root);
    void getMin(Node* node);

    Tree(int n,int *i,int *p){
        Min=9999;
        inOrder=i;
        postOrder=p;
        len=n;
        root= create(0,len-1,len-1);
    };
    ~Tree(){

    };
};

Node *Tree::create(int left,int right,int Root) {
    if (left>right)
        return nullptr;
    int newRoot=0;
    Node* node=new Node;
    for (int i = left; i <=right ; ++i) {
        if (inOrder[i]==postOrder[Root]){
            newRoot=i;
            break;
        }
    }
    node->data=postOrder[Root];
    node->left= create(left,newRoot-1,Root-1-(right-newRoot));
    node->right= create(newRoot+1,right,Root-1);
    return node;
}

void Tree::getMin(Node *node) {
    if (node){
        if (!node->left&&!node->right){
            Min= min(Min,node->data);
        }
        getMin(node->left);
        getMin(node->right);
    }
}

int main(){
    int n;
    while (cin>>n){
        int inOrder[10001],postOrder[10001];
        for (int i = 0; i < n; ++i) {
            cin>>inOrder[i];
        }
        for (int i = 0; i < n; ++i) {
            cin>>postOrder[i];
        }
        Tree t(n,inOrder,postOrder);
        t.getMin(t.root);
        cout<<t.Min<<endl;
    }
}