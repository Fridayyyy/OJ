//
// Created by 86184 on 2022/10/8.
//
#include <iostream>

using namespace std;

template<class T>
class qNode{
public:
    T value;
    qNode* next;
    qNode(T val,qNode* node= nullptr):value(val),next(node){}
};

template<class T>
class queue{
private:
    int size;
    qNode<T> *front;
    qNode<T> *back;
public:
    queue(){
        front= nullptr;
        back= nullptr;
        size=0;
    };

    bool empty(){
        return this->size==0;
    };

    T pop(){
        if (empty()){
            return nullptr;
        }
        qNode<T> *temp=front;
        front=front->next;
        if (back==front)
            back=front;
        size--;
        return temp->value;
    };
    void push(T val){
        size++;
        if (size==1){
            front=new qNode<T>(val, nullptr);
            back=front;
        } else{
            back->next=new qNode<T>(val, nullptr);
            back=back->next;
        }
    };
};


class Node{
public:
    char data;
    Node *left;
    Node *right;
    Node():left(nullptr),right(nullptr){}
};

class Tree{
private:
    int pos;
    Node *root;
    string strTree;
    Node* createTree();

    void mirror(Node* node);
    void pre(Node* node);
    void mid(Node* node);
    void post(Node* node);
    void BFS(Node* node);
public:
    Tree();
    ~Tree();
    void createTree(string str);
    void mirror();

    void pre();
    void mid();
    void post();
    void BFS();
};
Tree::Tree() {

}
Tree::~Tree() {

}
void Tree::createTree(string str) {
    pos=0;
    strTree.assign(str);
    root=createTree();
}

Node *Tree::createTree() {
    Node* T;
    char ch;
    ch=strTree[pos++];
    if (ch=='#'){
        T= nullptr;
    } else{
        T=new Node;
        T->data=ch;
        T->left=createTree();
        T->right=createTree();
    }
    return T;
}

void Tree::mirror() {
    mirror(this->root);
}

void Tree::mirror(Node *node) {
    if ((!node)||((node->left == NULL)&&(node->right == NULL)))
    {
        return;
    }

    Node* tmp = node->left;
    node->left = node->right;
    node->right = tmp;

    if (node->left)
        mirror(node->left);
    if (node->right)
        mirror(node->right);
}

void Tree::pre() {
    if(strTree[0]=='#')
        cout<<"NULL";
    else
        pre(root);
}

void Tree::pre(Node *node) {
    if (node== nullptr)
        return;
    cout<<node->data<<" ";
    pre(node->left);
    pre(node->right);
}
void Tree::mid() {
    if(strTree[0]=='#')
        cout<<"NULL";
    else
        mid(root);
}

void Tree::mid(Node *node) {
    if (!node)
        return;

    mid(node->left);
    cout<<node->data<<" ";
    mid(node->right);
}
void Tree::post() {
    if(strTree[0]=='#')
        cout<<"NULL";
    else
        post(root);
}

void Tree::post(Node *node) {
    if (node== nullptr)
        return;
    post(node->left);
    post(node->right);
    cout<<node->data<<" ";
}

void Tree::BFS() {
    if(strTree[0]=='#')
        cout<<"NULL";
    else
        BFS(root);
}

void Tree::BFS(Node *node) {
    if (!node)
        return;
    queue<Node*> queue;
    queue.push(node);
    while (!queue.empty()){
        Node* temp=queue.pop();
        cout<<temp->data<<" ";
        if (temp->left){
            queue.push(temp->left);
        }
        if (temp->right){
            queue.push(temp->right);
        }
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
        tree->mirror();

        tree->pre();
        cout<<endl;
        tree->mid();
        cout<<endl;
        tree->post();
        cout<<endl;

        tree->BFS();
        cout<<endl;
    }
}