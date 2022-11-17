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
        int temp=arr[0];
        if (temp==n) return 0;
        arr[0]=n;

        int index=len-1;
        while (arr[index]!=n){
            index--;
        }
        arr[0]=temp;
        return index>0?index+1:-1;
    }
};

int main(){
    Array a;
    a.F();
}