//
// Created by 86184 on 2022/9/22.
//
#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    int val;
    int flag=1;

    cin>>n;
    queue<int> que[n];
    unordered_map<int,int> maps;
    for (int i = 0; i < n; ++i) {
        int m;
        cin>>m;
        vector<int> vector;
        for (int j = 0; j < m; ++j) {
            cin>>val;
            maps.insert(make_pair(val,i));
        }
    }


    string str;
    while (cin>>str){

        if (str=="STOP"){
            break;
        } else if (str=="ENQUEUE"){
            cin>>val;

            for (int i = 0; i < n; ++i) {
                if (que[i].empty()||maps[que[i].front()]==maps[val]){
                    que[i].push(val);
                    break;
                }
            }

        } else if (str=="DEQUEUE"){
            for (int i = 0; i < n; ++i) {
                if (!que[i].empty()){
//                    if (flag){
//                        flag=0;
//                    } else{
//                        cout<<" ";
//                    }
                    cout<<que[i].front()<<" ";
                    que[i].pop();
                    break;
                }
            }
        }
    }
}


