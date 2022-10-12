//
// Created by 常贵杰 on 2022/8/31.
//
#include <vector>
#include <iostream>

using namespace std;
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int vec[2][3];
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                int num;
                cin>>num;
                vec[j][k]=num;
                //cout<<to_string(vec[j][k])<<endl;
            }
        }

        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 2; ++k) {
                cout<<to_string(vec[k][3-1-j])+" ";
            }
            cout<<endl;
        }
    }
}