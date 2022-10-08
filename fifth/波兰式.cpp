#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;

void bolan(string str){
    stack<char> stack1;
    stack<char> stack2;
    queue<char> que1;

    for (int i = str.size()-1; i >= 0; i--) {
        char c=str.at(i);
        if (c<='9'&&c>='0'){
            que1.push(c);
            if (i>0&&str.at(i-1)<='9'&&str.at(i-1)>='0'){
                continue;
            }
            while (!que1.empty()){
                stack2.push(que1.front());
                que1.pop();
            }
            stack2.push(' ');
        } else{
            if (c==')'){
                stack1.push(c);
            }
            if (c=='('){
                while (!stack1.empty()&&stack1.top()!=')'){
                    stack2.push(stack1.top());
                    stack2.push(' ');
                    stack1.pop();
                }
                stack1.pop();
            }
            if (c=='/'||c=='*'){
                stack1.push(c);
            }
            if (c=='+'||c=='-'){
                if (!stack1.empty()&&(stack1.top()=='*'||stack1.top()=='/')){
                    while (!stack1.empty()&&(stack1.top()=='*'||stack1.top()=='/')){
                        stack2.push(stack1.top());
                        stack2.push(' ');
                        stack1.pop();
                    }
                }
                stack1.push(c);
            }
        }
    }
    while (!stack1.empty()){
        stack2.push(stack1.top());
        stack2.push(' ');
        stack1.pop();
    }
    stack2.pop();
    while (!stack2.empty()){
        cout<<stack2.top();
        stack2.pop();
    }
    cout<<endl;
}
void niBolan(string str){
    queue<char> que1;
    queue<int> que2;
    stack<char> stk2;

    for (int i = 0; i < str.size(); ++i) {
        char c=str.at(i);
        if ('0'<=c&&c<='9'){
            que2.push(c);
            if ((i<str.size()-1)&&str.at(i+1)>='0'&&str.at(i+1)<='9'){
                continue;
            }

            int size=que2.size();
            for (int j = 0; j < size; ++j) {
                que1.push(que2.front());
                que2.pop();
            }
            que1.push(' ');

        } else{
            if (c=='/'||c=='*'){
                if (!stk2.empty()&&(stk2.top()=='*'||stk2.top()=='/')){
                    while (!stk2.empty()&&(stk2.top()=='*'||stk2.top()=='/')){
                        que1.push(stk2.top());
                        que1.push(' ');
                        stk2.pop();
                    }
                }
                stk2.push(c);
            }
            if (c=='-'||c=='+'){
                //如果遇到*和/
                if (!stk2.empty()&&(stk2.top()=='*'||stk2.top()=='/')){

                    while (!stk2.empty()&&(stk2.top()!='(')){
                        que1.push(stk2.top());
                        que1.push(' ');
                        stk2.pop();
                    }
                }
                stk2.push(c);
            }
            if (c=='('){
                stk2.push(c);
            }
            if (c==')'){
                while (stk2.top()!='('){
                    que1.push(stk2.top());
                    que1.push(' ');
                    stk2.pop();
                }
                stk2.pop();
            }
        }
    }
    while (!stk2.empty()){
        que1.push(stk2.top());
        que1.push(' ');
        stk2.pop();
    }
    int size=que1.size();
    for (int i = 1; i < size; ++i) {
        cout<<que1.front();
        que1.pop();
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        bolan(str);
        niBolan(str);
        if (i!=n-1){
            cout<<endl;
        }
    }
}