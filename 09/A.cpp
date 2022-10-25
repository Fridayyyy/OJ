//
// Created by 86184 on 2022/10/20.
//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;
const int MaxW=9999999;

class HuffNode{
public:
    int weight;
    int parent;
    int leftchild;
    int rightchild;
};
class HuffMan{
private:
    void MakeTree();
    void SelectMin(int pos,int *s1,int *s2);
public:
    int len;
    int lnum;
    HuffNode *huffTree;
    string *huffCode;
    void MakeTree(int n,int wt[]);
    void Coding();
    void Destroy();
};

void HuffMan::MakeTree(int n, int *wt) {
    //参数是叶子节点和叶子权值
    int i;
    lnum=n;
    len=2*n-1;
    huffTree=new HuffNode[2*n];
    huffCode=new string[lnum+1];
    for (i = 1; i <= n; ++i) {
        huffTree[i].weight=wt[i];
    }
    for (i = 1; i <= len; ++i) {
        if (i>n) huffTree[i].weight=0;

        huffTree[i].parent=0;
        huffTree[i].leftchild=0;
        huffTree[i].rightchild=0;
    }
    MakeTree();
}

void HuffMan::SelectMin(int pos, int *s1, int *s2) {
    int w1,w2,i;
    w1=w2=MaxW;
    *s1=*s2=0;
    for (i = 1; i <= pos; ++i) {
        if (huffTree[i].weight<w1 && huffTree[i].parent==0){
            w2=w1;
            *s2=*s1;
            *s1=i;
            w1=huffTree[i].weight;
        } else if (huffTree[i].weight<w2&&huffTree[i].parent==0){
            *s2=i;
            w2=huffTree[i].weight;
        }
    }
}

void HuffMan::MakeTree() {
    int i,s1,s2;
    for (i = lnum+1; i <= len; ++i) {
        SelectMin(i-1,&s1,&s2);
        huffTree[s1].parent=i;
        huffTree[s2].parent=i;
        huffTree[i].leftchild=s1;
        huffTree[i].rightchild=s2;
        huffTree[i].weight=huffTree[s1].weight+huffTree[s2].weight;
    }
}

void HuffMan::Destroy() {
    len=0;
    lnum=0;
    delete []huffTree;
    delete []huffCode;
}

void HuffMan::Coding() {
    char* cd;
    int i,c,f,start;
    cd=new char[lnum];
    cd[lnum-1]='\0';
    for (i = 1; i <= lnum; ++i) {
        start=lnum-1;
        c=i;f=huffTree[i].parent;
        while (f){
            if (huffTree[f].leftchild==c){
                cd[--start]='0';
            } else if (huffTree[f].rightchild==c){
                cd[--start]='1';
            }
            c=f;
            f=huffTree[c].parent;
        }
        huffCode[i].assign(&cd[start]);
    }
    delete[]cd;
}


int main(){
    int t,n,i,j;
    int wt[800];
    HuffMan myHuff;
    cin>>t;
    for (i = 0; i < t; ++i) {
        cin>>n;
        for (int k = 1; k <= n; ++k) {
            cin>>wt[k];
        }
        myHuff.MakeTree(n,wt);
        myHuff.Coding();

        for (j = 1; j <= n; ++j) {
            cout<<myHuff.huffTree[j].weight<<"-";
            cout<<myHuff.huffCode[j]<<endl;
        }
        myHuff.Destroy();
    }
    return 0;
}
