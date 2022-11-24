//
// Created by 86184 on 2022/11/23.
//
#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    explicit Node(int d){
        left= nullptr;
        right= nullptr;
        data=d;
    }
};

class Tree{
    int nodeNum;
    Node *root;
public:
    Tree(){
        root= nullptr;
        cin>>nodeNum;
        for (int i = 0; i < nodeNum; ++i) {
            int num;
            cin>>num;
            insert(num);
        }
        inOrder();
    }
    void insert(int num){
        Node *newNode=new Node(num);
        if (!root){
            root=newNode;
            return;
        }
        Node* temp=root;
        while (true){
            //cout<<temp->data<<endl;
            if (temp->data > num){
                if (temp->left){
                    temp=temp->left;
                } else{
                    temp->left=newNode;
                    break;
                }
            } else if (temp->data < num){
                if (temp->right){
                    temp=temp->right;
                } else{
                    temp->right=newNode;
                    break;
                }
            }
        }

    }
    void inOrder(){
        inOrder(root);
        cout<<endl;
    }
    void inOrder(Node* node){
        if (!node) return;
        inOrder(node->left);
        cout<<node->data<<" ";
        inOrder(node->right);
    }
    void main(){
        int n;
        cin>>n;
        for (int i = 0; i < n; ++i) {
            int num;
            cin>>num;
            insert(num);
            inOrder();
        }
    }
};

int main(){
    int t;
    cin>>t;
    while (t--){
        Tree t;
        t.main();
    }
}