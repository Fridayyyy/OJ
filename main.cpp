//
// Created by 86184 on 2022/9/23.
//
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class PoLand{
private:
    string str;

    queue<char> que1;
    stack<int> stk1;
    stack<char> stk2;

public:
    explicit PoLand(string str_):str(str_){}
    ~PoLand(){}
    void getInt();
    void boLan();
    void niBoLan();
};

void PoLand::getInt() {

}
void PoLand::boLan() {

}

void PoLand::niBoLan() {

    for (int i = 0; i < str.size(); ++i) {
        char c=str.at(i);
        if ('0'<=c&&c<='9'){
            que1.push(c);
        } else{
            if (c=='/'||c=='*'){
                stk2.push(c);
            }
            if (c=='-'||c=='+'){
                //如果遇到*和/
                if (!stk2.empty()&&(stk2.top()=='*'||stk2.top()=='/')){
                    //直到找到不是*和/
                    while (!stk2.empty()&&(stk2.top()!='*'||stk2.top()!='/')){
                        que1.push(stk2.top());
                        stk2.pop();
                    }
                    stk2.push(c);
                } else{
                    stk2.push(c);
                }
            }
            if (c=='('){
                stk2.push(c);
            }
            if (c==')'){
                while (stk2.top()!='('){
                    que1.push(stk2.top());
                    stk2.pop();
                }
                stk2.pop();
            }
        }
    }
    while (!stk2.empty()){
        que1.push(stk2.top());
        stk2.pop();
    }
    int size=que1.size();
    for (int i = 0; i < size-1; ++i) {
        if(str.at(i)>='0'&&str.at(i)<='9'&&str.at(i+1)>='0'&&str.at(i+1)<='9'){
            cout<<que1.front();
            que1.pop();
        } else{
            cout<<que1.front()<<" ";
            que1.pop();
        }
    }
    cout<<que1.front();
    que1.pop();

    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin>>str;
        PoLand* p=new PoLand(str);
        p->niBoLan();

        if (i!=n-1){
            cout<<endl;
        }
    }
}
