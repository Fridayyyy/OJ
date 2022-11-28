#include <iostream>

using namespace std;

class Node{
public:
    int val;
    int depth;
    Node* left;
    Node* right;
    Node* parent;
    //int height;
    Node(){
        left=parent=right= nullptr;

    }
    Node(int v){
        val=v;
        depth=0;
        left=right=parent= nullptr;
    }
};

class Tree{
    Node *root;

public:
    Tree(){

    }
    Tree(int v){
        root->val=v;
        root->depth=0;
    }

    int diff(Node* node){
        return getHeight(node->left)- getHeight(node->right);
    }
    void insert(int k){
        Node* newNode=new Node(k);
        if (!root){
            root=newNode;
            return;
            //return root;
        }
        Node* temp=root;
        while (true){

            if (temp->val > k){
                if (temp->left){
                    temp=temp->left;
                } else{
                    temp->left=newNode;
                    break;
                }
            } else if (temp->val < k){
                if (temp->right){
                    temp=temp->right;
                } else{
                    temp->right=newNode;
                    break;
                }
            }
        }
        root= balance(root);

    }
    void del(){

    }
    int getHeight(Node* node){
        if (!node){
            return 0;
        }
        int max;
        int left= getHeight(node->left);
        int right= getHeight(node->right);
        if (left>right)
            max=left;
        else
            max=right;
        return max+1;
    }
    Node* LL(Node* node){
        Node* temp;
        temp=node->left;
        node->left=temp->right;
        temp->right=node;
        return temp;
    }

    Node* RR(Node* node){
        Node* temp;
        temp=node->right;
        node->right=temp->left;
        temp->left=node;
        return temp;
    }
    Node* LR(Node* node){
        Node* temp;
        temp=node->left;
        node->left= RR(temp);
        return LL(node);
    }
    Node* RL(Node* node){
        Node* temp;
        temp=node->right;
        node->right= LL(temp);
        return RR(node);
    }

    Node* balance(Node* node){
        int bf= diff(node);
        if (bf>1){
            if (diff(node->left)>0){
                node= LL(node);
            } else
                node= LR(node);
        } else if (bf<-1){
            if (diff(node->right)>0)
                node= RL(node);
            else
                node= RR(node);
        }
        return node;
    }
    void main(){
        int choice;
        cin>>choice;
        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
            default:;
        }
    }
};

int main(){
    int t;
    cin>>t;
    Tree tree;
    while (t--){
        tree.main();
    }
}