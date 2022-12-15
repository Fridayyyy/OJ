#include <iostream>
#include <vector>
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
    void sort(){
        vector<vector<int>> res;
        int s=10;

        for (int i = 0; i < n; ++i) {
            int temp=nums[i]%10;
            res[temp].push_back(nums[i]);
        }
    }
    void main(){
        sort();
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