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


    void del(int num){
        Node *temp=root,*previous=root;

        while (temp){
            if (temp->data==num){
                break;
            } else if (temp->data>num){
                previous=temp;
                temp=temp->left;
            } else if (temp->data<num){
                previous=temp;
                temp=temp->right;
            }
        }

        if (temp){

            if (!temp->left && !temp->right){
                previous->left==temp?previous->left= nullptr:previous->right= nullptr;
                delete temp;

            } else if (!temp->left && temp->right){

                previous->left==temp?previous->left= temp->right:previous->right= temp->right;

            } else if (!temp->right && temp->left){

                previous->left==temp?previous->left= temp->left:previous->right= temp->left;
            } else if (temp->left && temp->right){
                Node *right_min=temp->right;
                previous=right_min;
                while (right_min->left){
                    previous=right_min;
                    right_min=right_min->left;
                }

                temp->data=right_min->data;
                if (right_min==previous){
                    temp->right=right_min->right;
                } else{
                    previous->left=right_min->right;
                }
            }
        }
    }

    void main(){
        int n;
        cin>>n;
        while (n--){
            int num;
            cin>>num;
            del(num);
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