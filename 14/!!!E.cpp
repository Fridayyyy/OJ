#include <iostream>

using namespace std;


class Tree{
    int num;
    char *tree;
public:
    Tree(){
        cin>>num;
        tree=new char[num+1];
        for (int i = 1; i <= num; ++i) {
            cin>>tree[i];
        }
    }
    void postOrder(int pos){
        if (tree[pos]!='0' && pos<=num){
            postOrder(2*pos);
            postOrder(2*pos+1);
            balanceFactor(pos);
        }
    }
    void balanceFactor(int pos){
        int temp;
        if (pos*2>num){
            cout<<tree[pos]<<" 0"<<endl;
        } else if (2*pos==num && 2*pos+1>num){
            cout<<tree[pos]<<" 1"<<endl;
        } else{
            temp= depth(2*pos)- depth(2*pos+1);
            cout<<tree[pos]<<" "<<temp<<endl;
        }
    }

    int depth(int pos){
        int dep=0,maxDep=0;
        getDepth(pos,dep,maxDep);
        return maxDep;
    }
    void getDepth(int pos,int depth,int &maxDepth){
        if (tree[pos]!='0' && pos<=num){
            depth++;
            if (maxDepth<depth)
                maxDepth=depth;
            getDepth(2*pos,depth,maxDepth);
            getDepth(2*pos+1,depth,maxDepth);
        }
    }

    void main(){
        postOrder(1);
    }
};
int main(){
    int t;
    cin>>t;
    while (t--){
        Tree tree;
        tree.main();
    }
}