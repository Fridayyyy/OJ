//
// Created by 86184 on 2022/9/15.
//
#include <stack>
#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int n;
    cin>>n;
    unordered_map<char,char> map;
    map.insert(make_pair(')','('));
    map.insert(make_pair(']','['));
    map.insert(make_pair('}','{'));

    for (int i = 0; i < n; ++i) {
        stack<char> stk;
        string str;
        cin>>str;
        for (char c : str) {
            if (c=='('||c=='{'||c=='['){
                stk.push(c);
            } else if (c==')'||c==']'||c=='}'){
                if (stk.empty()){
                    stk.push(c);
                    break;
                } else{
                    if (map[c]==stk.top()){
                        stk.pop();
                        continue;
                    } else{
                        break;
                    }
                }
            }
        }
        if (stk.empty()){
            cout<<"ok"<<endl;
        } else{
            cout<<"error"<<endl;
        }
    }
    return 0;
}