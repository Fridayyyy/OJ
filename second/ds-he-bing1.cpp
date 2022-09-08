//
// Created by 常贵杰 on 2022/9/1.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main(){
    int m,n;
    cin>>m;
    vector<int> vec;
    for (int i = 0; i < m; ++i) {
        int val;
        cin>>val;
        vec.push_back(val);
    }
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int val;
        cin>>val;
        vec.push_back(val);
    }
    sort(vec.begin(), vec.end());
    cout<<vec.size()<<" ";
    print(vec);
    return 0;
}
