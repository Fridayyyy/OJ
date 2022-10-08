//
// Created by 86184 on 2022/9/28.
//
#include <iostream>
#include <string>
using namespace std;

string matched_Prefix_Postfix(string str){
    string res="empty";
    if (str.size()==1)
        return res;

    for (int i = 1; i < str.size(); ++i) {
        if (str.substr(0,i)==str.substr(str.size()-1-i,i)){
            res=str.substr(0,i);
        }
    }
    return res;

}

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string str;
        cin>>str;
        cout<<matched_Prefix_Postfix(str)<<endl;
    }
}