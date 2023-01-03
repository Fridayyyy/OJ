#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Stack{
    int n;
    string in;
    string out;
public:
    Stack(){
        cin>>n>>in>>out;
    }
    vector<string> Finish(){
        vector<string> res;
        stack<char> stk;
        int p=0,q=0;
        for (int i = 0; i < n; ++i) {
            stk.push(in.at(i));
            res.emplace_back("in");

            if (stk.top()==out.at(q) && q<n){
                q++;
                stk.pop();
                res.emplace_back("out");
            }
        }

        while (!stk.empty()){
            if (stk.top()==out.at(q) && q<n){
                q++;
                stk.pop();
                res.emplace_back("out");
            } else{
                res.clear();
                return res;
            }
        }

        return res;

    }
    void main(){
        auto temp=Finish();
        if (temp.empty()){
            cout<<"No"<<endl;
        } else{
            cout<<"Yes"<<endl;
            int t=temp.size();
            for (int i = 0; i < t; ++i) {
                cout<<temp[i]<<endl;
            }
        }
        cout<<"FINISH"<<endl;
    }
};


int main(){
    int t;
    cin>>t;
    while (t--){
        Stack s;
        s.main();
    }
}