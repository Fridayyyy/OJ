#include <iostream>

using namespace std;

class Node{
public:
    int key;
    int balanceFactor;
    Node* left;
    Node* right;
    //Node* parent;
    //int height;
    Node(){
        left=right= nullptr;
    }
//    Node(int d){
//        data=d;
//        left=right=parent= nullptr;
//    }
};

class Tree{
    Node *root;

public:
    void updateHeight(){


    }
    int heightDiff(){

    }
    void insert(){

    }
    void del(){

    }
    int LL(){

    }
    int RR(){

    }
    int LR(){

    }
    int RL(){

    }

    void main(){
        int choice;
        cin>>choice;
        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
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