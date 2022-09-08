#include <iostream>

using namespace std;
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int size;
        cin>>size;
        int temp[size];
        for (int j = 0; j < size; ++j) {
            int val;
            cin>>val;
            temp[j]=val;
        }
        int th;
        cin>>th;
        cout<<temp[(size)/2-1]<<" "<<temp[(size)/2+1]<<endl;
        cout<<temp[th-1]<<endl;
    }

}

