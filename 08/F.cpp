#include <iostream>

using namespace std;

int B;

class BNode{
public:
    char data;
    BNode *left;
    BNode *right;
    BNode(){
        left= nullptr;
        right= nullptr;
    }
};

class BTree{
    BNode *root;
    void get_leaves(BNode* t,string str){
        if (t){
            if (!t->left&&!t->right){
                cout<<str<<endl;
            } else{
                get_leaves(t->left,str+"0 ");
                get_leaves(t->right,str+"1 ");
            }
        }
    }
public:
    void merge(BNode **t,int N){
        root=t[0];
        for (int i = 0; i < N-1; ++i) {
            t[i]->right=t[i+1];
        }
    }
    void getCode(){
        string str="";
        get_leaves(root,str);
    }
};

class TreeNode{
public:
    char data;
    TreeNode **child;
    TreeNode(int n){
        child=new TreeNode *[n];
        for (int i = 0; i < n; ++i) {
            child[i]=nullptr;
        }
    }
};
class Tree{
    TreeNode* root;
public:
    Tree(){
        root=createTree();
    }
    TreeNode* createTree();
    BNode* getBTree(){
        return transfer(root);
    }
    BNode* transfer(TreeNode* t);
};

TreeNode *Tree::createTree() {
    TreeNode* p;
    char ch;
    cin>>ch;
    if (ch=='0'){
        p= nullptr;
    } else{
        p=new TreeNode(B);
        p->data=ch;
        for (int i = 0; i < B; ++i) {
            p->child[i]=createTree();
        }
    }
    return p;
}

BNode *Tree::transfer(TreeNode *t) {
    BNode* p= nullptr;
    if (t){
        p=new BNode;
        p->data=t->data;
        p->left= transfer(t->child[0]);
        if (p->left){
            BNode *q=p->left;
            for (int i = 1; i < B; ++i) {
                q->right= transfer(t->child[i]);
                if (q->right)
                    q=q->right;
            }
        }
    }
    return p;
}
int main(){
    int N;
    cin>>N>>B;
    Tree *p=new Tree[N];
    BNode **q=new BNode *[N];

    for (int i = 0; i < N; ++i) {
        q[i]=p[i].getBTree();
    }
    BTree bt;
    bt.merge(q,N);
    bt.getCode();
    return 0;
}