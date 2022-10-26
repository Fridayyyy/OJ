#include <iostream>

#define ok 1
#define error -1
const int maxW= 9999;

using namespace std;

class HuffNode{
public:
    int weight;
    int parent;
    int left;
    int right;
    char data;
};
class HUffTree{
    void SelectMin(int pos,int *s1,int *s2){
        int w1,w2;
        w1=w2= maxW;
        *s1=*s2=0;
        for (int i = 1; i <= pos; ++i) {
            if (huffTree[i].parent==0 && huffTree[i].weight<w1){
                w2=w1;
                *s2=*s1;
                w1=huffTree[i].weight;
                *s1=i;

            } else if (huffTree[i].parent==0 && huffTree[i].weight<w2){
                *s2=i;
                w2=huffTree[i].weight;
            }
        }
    }
    void MakeTree(){
        for (int i = lnum+1; i <= len; ++i) {
            int s1,s2;
            SelectMin(i-1,&s1,&s2);
            huffTree[s1].parent=i;
            huffTree[s2].parent=i;

            huffTree[i].weight=huffTree[s1].weight+huffTree[s2].weight;
            huffTree[i].left=s1;
            huffTree[i].right=s2;
        }
    }
public:
    int len;
    int lnum;
    HuffNode* huffTree;
    string *huffCode;
    void MakeTree(int n,int wt[],char nm[]){
        lnum=n;
        len=2*n-1;
        huffTree=new HuffNode[2*n];
        huffCode=new string[lnum+1];

        for (int i = 1; i <= n; ++i) {
            huffTree[i].weight=wt[i-1];
            huffTree[i].data=nm[i-1];
        }
        for (int i = 1; i <= len; ++i) {
            if (i>n)
                huffTree[i].weight=0;
            huffTree[i].parent=0;
            huffTree[i].left=0;
            huffTree[i].right=0;
        }
        MakeTree();
    }
    void Destroy(){
        len=0;
        lnum=0;
        delete []huffTree;
        delete []huffCode;
    }
    void Code(){
        char *cd=new char[lnum];
        cd[lnum-1]='\0';
        int child;int parent;

        for (int i = 1; i <= lnum; ++i) {
            int start=lnum-1;
            child=i;parent=huffTree[i].parent;
            while (parent){
                if (huffTree[i].left==child){
                    cd[--start]='0';
                } else if (huffTree[i].right==child){
                    cd[--start]='1';
                }
                child=parent;
                parent=huffTree[i].parent;
            }
            huffCode[i].assign(&cd[start]);
        }

        delete[] cd;
    }
    int Decode(const string codestr,char txtstr[]){
        int k,c;
        char ch;
        c=len;
        k=0;
        for (int i = 0; i < codestr.size(); ++i) {
            ch=codestr[i];
            if (ch=='0'){
                c=huffTree[c].left;
            }
            if (ch=='1'){
                c=huffTree[c].right;
            }
            if (ch!='0' && ch!='1'){
                return error;
            }
            if (!huffTree[c].left && !huffTree[c].right){
                txtstr[k++]=huffTree[c].data;
                c=len;
            } else{
                ch='\0';
            }
        }
        if (ch=='\0') return error;
        else txtstr[k]='\0';
        return ok;
    }
};
int main(){
    int t;
    cin>>t;

    int wt[999];
    char chars[999];
    while (t--){
        int n;
        cin>>n;
        for (int i = 0; i < n; ++i) {
            cin>>wt[i];
        }
        for (int i = 0; i < n; ++i) {
            cin>>chars[i];
        }
        HUffTree huffTree;
        huffTree.MakeTree(n,wt,chars);


//        for (int i = 1; i <= 2*n; ++i) {
//            cout<<huffTree.huffTree[i].weight<<" ";
//        }
//        cout<<endl;

        int m;
        cin>>m;
        while (m--){
            string str;
            cin>>str;

            char txt[999];
            if (huffTree.Decode(str,txt)!=-1){
                cout<<txt<<endl;
            } else{
                cout<<"error"<<endl;
            }
        }
    }
}