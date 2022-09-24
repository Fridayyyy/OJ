//
// Created by 86184 on 2022/9/23.
//
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<pair<int,int>> findPath(vector<vector<int>> vec,int j,int k){
    if (j>=vec.size()||k>=vec.size()){
        return vector<pair<int,int>>(0);
    }
}
void display(vector<pair<int,int>> vec){
    if (vec.size()==0){
        cout<<"no path"<<endl;
        return;
    }
    //TODO
}

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int size,val;
        cin>>size;
        vector<vector<int>> vec(size,vector<int>(size));
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                cin>>val;
                vec[i][j]=val;
            }
        }

        auto t=findPath(vec,0,0);
        display(t);
    }
}
