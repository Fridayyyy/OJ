#include <iostream>

using namespace std;

class Insert{
    int n;
    int *nums;

public:
    Insert(){
        cin>>n;
        nums=new int[n+1];
        for (int i = 1; i <= n; ++i) {
            cin>>nums[i];
        }
    }
    void sort(int left,int right){
        if (left>right)
            return;

        int temp=nums[left];

        int i=left,j=right;
        while (i<j){

            while (nums[j]>=temp && i<j){
                j--;
            }

            swap(nums[i],nums[j]);

            while (nums[i]<=temp && i<j){
                i++;
            }
            swap(nums[i],nums[j]);
        }

        cout << nums[i] << " " << i << endl;
        //display();
        sort(left,i-1);
        sort(i+1,right);
    }

    void display(){
        for (int i = 1; i <= n; ++i) {
            cout<<nums[i];
            if (i!=n){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    void main(){
        sort(1,n);
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