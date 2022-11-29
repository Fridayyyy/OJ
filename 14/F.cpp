#include <iostream>

using namespace std;
const int MAX=99999;
const int MIN=-1;
class Node{
public:
    int key;
    int data;
    Node* left;
    Node* right;
    Node(){
        left=right= nullptr;
    }
    Node(int d,int k){
        key=k;
        data=d;

        left=right= nullptr;
    }
};

class Tree{
    Node *root;

public:
    Tree(){
        root= nullptr;
    }
    Tree(int d,int k){
        root= new Node(d,k);

    }

    void display(){
        auto temp=root;
        display(temp);
        cout<<endl;
    }
    void display(Node* node){
        if (!node){
            return;
        }
        cout<<node->key<<" ";
        display(node->left);
        display(node->right);
    }

    int diff(Node* node){
        return getHeight(node->left)- getHeight(node->right);
    }
    void insert(int d,int k){
        Node* newNode=new Node(d,k);
        if (!root){
            root=newNode;
            return;
        }
        Node* temp=root;
        while (true){

            if (temp->key > k){
                if (temp->left){
                    temp=temp->left;
                } else{
                    temp->left=newNode;
                    break;
                }
            } else if (temp->key < k){
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
    Node* binaryTreeSearch(Node *node,int k){
        if(node->key==k)
            return node;

        else if(node->key>k){
            if(node->left!= nullptr)
                return binaryTreeSearch(node->left,k);
            else return nullptr;
        }

        else{
            if(node->right!= nullptr)
                return binaryTreeSearch(node->right,k);
            else
                return nullptr;
        }
    }

    void del(int k){
        root=del(root,k);
    }
    Node* del(Node* node,int k){
        if (!node)
            return node;
//        if (!binaryTreeSearch(root,k)){
//            cout<<'0'<<endl;
//            return node;
//        }
        if (k==node->key){
            cout<<node->data<<endl;
            if (node->left && node->right){
                if (diff(node)>0){
                    getMax(node->left,node->key);
                    node->left= del(node->right,node->key);
                } else{
                    getMin(node->right,node->key);
                    node->right= del(node->right,node->key);
                }
            } else{
                Node* tmp=node;
                node=(node->left)?(node->left):(node->right);
                delete tmp;
                tmp= nullptr;
            }
        } else if (k<node->key){
            node->left= del(node->left,k);
            if (diff(node)<-1){
                if (diff(node->right) > 0){
                    node= RL(node);
                } else
                    node= RR(node);
            }
        } else{
            node->right= del(node->right,k);
            if (diff(root)>1){
                if (diff(node->left)<0){
                    node= LR(node);
                } else{
                    node= LL(node);
                }
            }
        }
        return node;
    }

    int getMax(){
        int temp=MIN;
        getMax(root,temp);
        return temp;
    }
    void getMax(Node* node,int& k){
        if (!node)
            return;
        if (node->key>k){
            k=node->key;
        }
        getMax(node->left,k);
        getMax(node->right,k);
    }
    int getMin(){
        int temp=MAX;
        getMin(root,temp);
        return temp;
    }
    void getMin(Node* node,int &k){
        if (!node)
            return;
        if (node->key<k){
            k=node->key;
        }
        getMin(node->left,k);
        getMin(node->right,k);
    }
    int getHeight(Node* node){
        if (node== nullptr){
            return 0;
        }
        int max,left=0,right=0;

        if (node->left){
            left= getHeight(node->left);
        }
        if (node->right){
            right= getHeight(node->right);
        }

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
                int d,k;
                cin>>d>>k;
                insert(d,k);
                //display();
                break;
            case 2:
                int temp1;
                temp1=getMax();
                if (temp1!=MIN){
                    //cout<<temp1<<endl;
                    del(temp1);
                } else{
                    cout<<'0'<<endl;
                }
                break;
            case 3:
                int temp2;
                temp2=getMin();
                if (temp2!=MAX){
                    //cout<<temp2<<endl;
                    del(temp2);
                } else{
                    cout<<'0'<<endl;
                }
                break;
            case 4:
                int del_k;
                cin>>del_k;
                del(del_k);

                Node* temp;
                temp=root;
                if (!binaryTreeSearch(temp,del_k)){
                    cout<<'0'<<endl;
                } else
                    del(del_k);

                //display();
                break;
            default:
                cout<<"error"<<endl;
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