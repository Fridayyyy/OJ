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


        for (int i = n/2; i > 0 ; i--) {
            adjust(i,n);
        }
    }
    void sort(){
        display();
        for (int i = n; i >1; --i) {
            swap(nums[i],nums[1]);
            adjust(1,i-1);
            display();
        }

    }

    void adjust(int k,int len){
        nums[0]=nums[k];
        for (int i = k*2; i <= len; i *= 2) {
            if (nums[i]>nums[i+1] && i<len)
                i++;
            if (nums[0]<=nums[i])
                break;
            else{
                nums[k]=nums[i];
                k=i;
            }
        }
        nums[k]=nums[0];
    }

    void display(){
        cout<<n<<" ";
        for (int i = 1; i <= n; ++i) {
            cout<<nums[i];
            if (i!=n){
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
    Insert i;
    i.main();
}