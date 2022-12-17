#include <iostream>
#include <vector>

using namespace std;

int Pow(int a,int b){
    if (b==0) return 1;
    for (int i = 1; i < b; ++i) {
        a*=a;
    }
    return a;
}

class Sort{
    int l;
    int n;
    int *nums;
public:
    Sort(){
        cin>>n;
        nums=new int[n];

        l=0;
        int max=0;

        for (int i = 0; i < n; ++i) {
            cin>>nums[i];
            if (nums[i]>=max){
                max=nums[i];
            }

        }
        //cout<<max<<endl;
        while (max){
            max/=10;
            l++;
        }
        //cout<<l<<endl;
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
        vector<vector<int>> matrix;
        for (int i = 0; i < 10; ++i) {
            vector<int> temp;
            matrix.push_back(temp);
        }

        int t=1;
        while (t<=l){
            for (int i = 0; i < n; ++i) {
                int temp=nums[i];
                temp%=Pow(10,t);
                temp/= Pow(10,t-1);
                matrix[temp].push_back(nums[i]);
            }
            int pos=0;
            for (int i = 0; i < 10; ++i) {
                cout<<i<<":";
                if (matrix[i].empty())
                    cout<<"NULL"<<endl;
                else{
                    for (int j = 0; j < matrix[i].size(); ++j) {
                        cout<<"->"<<matrix[i][j];
                        nums[pos++]=matrix[i][j];
                    }
                    cout<<"->^"<<endl;
                    matrix[i].clear();
                }
            }

            display();
            t++;
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
        if (t>0){
            cout<<endl;
        }
    }
    return 0;
}