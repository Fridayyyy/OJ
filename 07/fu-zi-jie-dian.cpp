#include <iostream>
#include <queue>

using namespace std;

class Node{
public:
    char val;
    Node* left;
    Node* right;

    Node(char ch){
        left= nullptr;
        right= nullptr;
        val=ch;
    }
};
class Tree{

    Node* root;
    int pos;
    string str;
    Node* createTree();
    void getCh(Node* node);
    void getF(Node* node);
public:
    void createTree(string s);
    void getCh();
    void getF();
};

void Tree::createTree(std::string s) {
    pos=0;
    str.assign(s);
    root=createTree();
}

Node* Tree::createTree() {
    Node* T;
    char ch;
    ch=str.at(pos++);
    if (ch=='0')
        T= nullptr;
    else{
        T=new Node(ch);
        T->left=createTree();
        T->right=createTree();
    }
    return T;
}

void Tree::getCh(Node *node) {
    if (node){
        if (!node->left&&!node->right)
            cout<<node->val<<" ";
        getCh(node->left);
        getCh(node->right);
    }
}

void Tree::getCh() {
    getCh(root);
}

void Tree::getF() {
    getF(root);
}

void Tree::getF(Node *node) {
    if (node){
        if (node->left){
            if (!node->left->left&&!node->left->right)
                cout<<node->val<<" ";
        }
        getF(node->left);

        if (node->right){
            if (!node->right->left&&!node->right->right)
                cout<<node->val<<" ";
        }
        getF(node->right);
    }
}


int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin>>str;
        Tree* tree=new Tree;
        tree->createTree(str);
        tree->getCh();
        cout<<endl;

        tree->getF();
        cout<<endl;
    }
}
