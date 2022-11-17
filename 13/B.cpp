#include <iostream>

using namespace std;

class Array{
private:
    int len;
    int *arr;
public:
    Array(){
        cin>>len;
        arr=new int[len];
        for (int i = 0; i < len; ++i) {
            cin>>arr[i];
        }
    }
    void F(){
        int t;
        cin>>t;
        while (t--){
            int num;
            cin>>num;
            if (find(num)==-1){
                cout<<"error"<<endl;
            } else{
                cout<<find(num)<<endl;
            }

        }
    }
    int find(int n){
        int left=0,right=len;
        int temp=len/2;
        while (arr[temp]!=n && left<right){
            if (arr[temp]>n){
                right=temp;
            } else if (arr[temp]<n){
                left=temp+1;
            }
            temp=(left+right)/2;
        }
        return arr[temp]==n?temp+1:-1;
    }
};

int main(){
    Array a;
    a.F();
}