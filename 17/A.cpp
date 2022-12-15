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
    void sort(){
        int temp,min;
        for (int i = 0; i < n-1; ++i) {
            min=i;
            for (int j = i+1; j < n; ++j) {
                if (nums[j]<nums[min]){
                    min=j;
                }
            }
            temp=nums[i];
            nums[i]=nums[min];
            nums[min]=temp;
            display();
        }
        display();
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
        if (t>0){
            cout<<endl;
        }
    }
}