#include <iostream>

using namespace std;

class insert{
    int n;
    int *nums;
public:
    insert(){
        cin>>n;
        nums=new int[n];
        for (int i = 0; i < n; ++i) {
            cin>>nums[i];
        }
    }
    void sort(){
        for (int i = 1; i < n; ++i) {
            if (nums[i]<nums[i-1]){
                int temp=nums[i];
                int j=i-1;
                for (; nums[j] > temp && j>=0; --j) {
                    nums[j+1]=nums[j];
                }
                nums[j+1]=temp;
            }
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

};

int main(){
    insert i;
    i.sort();
}