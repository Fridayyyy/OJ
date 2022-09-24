//
// Created by 86184 on 2022/9/15.
//
#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main(){
    stack<char> stk;
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin>>str;
        for (int j = 0; j < str.size(); ++j) {
            stk.push(str.at(j));
        }
        while (!stk.empty()){
            cout<<stk.top();
            stk.pop();
        }
        cout<<endl;
    }

}