#include <iostream>

using namespace std;

class Sort{
    int n;
    int *nums;
public:
    Sort(){
        cin>>n;
        nums=new int[n];
        for (int i = 0; i < n; ++i) {
            cin>>nums[i];
        }
    }
    void display(){
        for (int i = 0; i < n; ++i) {
            cout<<nums[i];
            if (i!=n-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    void main(){

    }
};



int main(){
    int t;
    cin>>t;
    while (t--){
        Sort s;
        s.main();
    }
}