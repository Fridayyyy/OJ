//
// Created by 86184 on 2022/11/3.
//
#include <iostream>
#include <queue>

using namespace std;

class Graph{
    vector<vector<int>> vec;
    int vexNum;
    vector<bool> isVisited;
public:
    Graph(){
        cin>>vexNum;
        vec=vector<vector<int>>(vexNum,vector<int>(vexNum));
        for (int i = 0; i < vexNum; ++i) {
            for (int j = 0; j < vexNum; ++j) {
                cin>>vec[i][j];
            }
        }
    };
    void BFS(){
        isVisited=vector<bool>(vexNum);
        for (int i = 0; i < vexNum; ++i) {
            isVisited[i]=0;
        }
        queue<int> que;
        for (int i = 0; i < vexNum; ++i) {
            if (!isVisited[i]){
                isVisited[i]=1;
                cout<<i<<" ";
                que.push(i);
                while (!que.empty()){
                    int temp=que.front();
                    que.pop();
                    for (int j = 0; j < vexNum; ++j) {
                        if (!isVisited[j] && vec[temp][j]==1){
                            cout<<j<<" ";
                            isVisited[j]=1;
                            que.push(j);
                        }
                    }
                }
            }
        }
    }
};

int main(){
    int t;
    cin>>t;
    while (t--){
        Graph g;
        g.BFS();
        cout<<endl;
    }
}