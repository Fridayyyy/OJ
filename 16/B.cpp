#include <iostream>

using namespace std;

class Insert{
    int *nums;
    int n;
    int count;

public:
    Insert(int c){
        n=c;
        nums=new int[n];
        for (int i = 0; i < n; ++i) {
            cin>>nums[i];
        }
        count=0;
    }

    void sort(){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i-1; ++j) {
                if (nums[j]>nums[j+1]){
                    count++;
                    int temp=nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=temp;
                }
            }
        }
    }
    void display(){
        for (int i = 0; i < n; ++i) {
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }

    void main(){
        sort();
        //display();
        cout<<count<<endl;
    }
};

int main(){
    int n;
    while (cin>>n && n!=EOF){
        Insert i(n);
        i.main();
    }
}