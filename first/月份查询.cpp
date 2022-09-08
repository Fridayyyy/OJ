//
// Created by 常贵杰 on 2022/8/25.
//
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(){
    vector<string> vec={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int n;
    int temp;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>temp;
        cout<<vec[temp]<<endl;
    }
    return 0;
}
