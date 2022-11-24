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

    int find(int num){
        int count=0;
        Node* temp=root;
        while (temp){
            count++;
            if (temp->data==num){
                return count;
            }
            if (temp->data<num){
                temp=temp->right;
            } else if (temp->data>num){
                temp=temp->left;
            }
        }

        return -1;
    }
    void main(){
        int n;
        cin>>n;
        while (n--){
            int num;
            cin>>num;
            cout<<find(num)<<endl;
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