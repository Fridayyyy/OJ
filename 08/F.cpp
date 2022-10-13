#include <iostream>
using namespace std;

int B;

struct BiNode{
    char data;
    BiNode *lChild;
    BiNode *rChild;
    BiNode():lChild(NULL),rChild(NULL){}
};
struct TreeNode{
    char data;
    TreeNode **child;
    TreeNode(int b){
        child=new TreeNode * [b];
        for (int i = 0; i < b; ++i) {
            child[i]= nullptr;
        }
    }
};
class Tree{
    TreeNode* root;
public:
    Tree(){
        root=CreateTree();
    }
    TreeNode* CreateTree();
    BiNode* getBiTree(){
        return transferToBT(root);
    }
    BiNode* transferToBT(TreeNode *t);
};

TreeNode *Tree::CreateTree() {
    TreeNode *p;
    char ch;
    cin>>ch;
    if (ch=='0'){
        p= nullptr;
    } else{
        p=new TreeNode(B);
        p->data=ch;
        for (int i = 0; i < B; ++i) {
            p->child[i]=CreateTree();
        }
    }
    return p;
}

BiNode *Tree::transferToBT(TreeNode *t) {
    BiNode* p= nullptr;
    if (t){
        p=new BiNode;
        p->data=t->data;
        p->lChild= transferToBT(t->child[0]);
        if (p->lChild){
            BiNode *q=p->lChild;
            for (int i = 1; i < B; ++i) {
                q->rChild= transferToBT(t->child[i]);
                if (q->rChild){
                    q=q->rChild;
                }
            }
        }
    }
    return p;
}

class BiTree{
    BiNode *root;
    void get_leaves(BiNode* t,string str){
        if (t){
            if (!t->lChild&&!t->rChild){
                cout<<str<<endl;
            }
            get_leaves(t->lChild,str+"0 ");
            get_leaves(t->rChild,str+"1 ");
        }
    }
public:
    void merge(BiNode **t,int N){
        root=t[0];
        for (int i = 0; i < N-1; ++i) {
            t[i]->rChild=t[i+1];
        }
    }
    void get_leavesCode(){
        string str="";
        get_leaves(root,str);
    }
};

int main(){
    int N;
    cin>>N>>B;
    Tree *p=new Tree[N];
    BiNode **q=new BiNode *[N];

    for (int i = 0; i < N; ++i) {
        q[i]=p[i].getBiTree();
    }
    BiTree biT;
    biT.merge(q,N);
    biT.get_leavesCode();

    return 0;
}
