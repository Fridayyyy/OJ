#include <iostream>
#include <vector>

using namespace std;

void pre(vector<int>vec,int i){
    if (vec[i]!=0&&i<vec.size()){
        cout<<vec[i]<<" ";
        pre(vec,2*i+1);
        pre(vec,2*i+2);
    }
}

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int length;
        cin>>length;
        vector<int> vec;
        for (int j = 0; j < length; ++j) {
            int num;
            cin>>num;
//            if (num!=0)
            vec.push_back(num);
        }
        pre(vec,0);
        cout<<endl;
    }
}