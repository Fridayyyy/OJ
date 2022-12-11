#include <iostream>

using namespace std;

class Insert{
    int n;
    int *nums;

public:

    Insert(){
        cin>>n;
        nums=new int[n];
        for (int i = 0; i < n; ++i) {
            cin>>nums[i];
        }
    }
    void sort(){
        for (int i = 1; i < n; ++i) {
            int temp=nums[i];
            int left=0,right=i-1,mid;
            while (left<=right){
                mid=(left+right)/2;
                if (temp<nums[mid]){
                    left=mid+1;
                } else{
                    right=mid-1;
                }
            }
            for (int j = i; j >= left; --j) {
                nums[j]=nums[j-1];
            }
            nums[left]=temp;
            display();
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
        sort();
    }
};



int main(){
    int t;
    cin>>t;
    while (t--){
        Insert i;
        i.main();
        if (t>0){
            cout<<endl;
        }
    }
}