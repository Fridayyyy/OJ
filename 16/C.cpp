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
        int gap=n;
        while (true){
            gap/=2;

            for (int i = 0; i < gap; ++i) {
                for (int j = i+gap; j < n; j+=gap) {
                    if (nums[j] > nums[j-gap]){
                        int temp=nums[j];

                        int k;
                        for (k = j-gap; k>=0 && nums[k] < temp; k-=gap) {
                            nums[k+gap]=nums[k];
                        }

                        nums[k+gap]=temp;


                    }

                }

            }
            display();

            if (gap==1){
                break;
            }
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