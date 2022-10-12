#include <stack>
#include <iostream>

using namespace std;

void helper(string str){
    stack<char> stk,stk1;
    for (char c : str) {
        if (c=='#'){
            if (stk.empty()){
                continue;
            } else{
                stk.pop();
            }
        } else{
            stk.push(c);
        }
    }
    if (stk.empty()){
        cout<<"NULL"<<endl;
        return;
    }
    while (!stk.empty()){
        stk1.push(stk.top());
        stk.pop();
    }
    while (!stk1.empty()){
        cout<<stk1.top();
        stk1.pop();
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin>>str;

        helper(str);
    }
    return 0;
}