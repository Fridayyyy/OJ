#include <iostream>

using namespace std;



class Tree{
    int t;
    int *a;
    int *b;
public:
    Tree(){
        int n;
        cin>>n;
        t=n*(n-1)*(n-2);

        a=new int[t];
        b=new int[t];
        for (int i = 0; i < t; ++i) {
            a[i]=b[i]=0;
        }

        int i,j,k,flag;
        for (int l = 0; l < t; ++l) {
            cin>>i>>j>>k>>flag;
            if (flag==1){
                a[k]++;
                b[k]=j;
            }
        }

    }
    void main(){
        int temp=0,i=0,sum=1;

        for (int j = 0; j < t; ++j) {
            if (a[j]>a[temp])
                temp=j;
        }
        for (int j = 0; j < t; ++j) {
            if (temp==b[j])
                sum=0;
        }
        if (sum==1){
            cout<<temp<<endl;
        }
    }
};

int main(){
    Tree t;
    t.main();
}