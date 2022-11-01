#include <iostream>
#include <queue>

using namespace std;
const int maxLen=20;

class Map{
    int Matrix[maxLen][maxLen];
    int vexNum;
    bool Visit[maxLen];
public:
    void SetMatrix();
    void BFS();
};

void Map::SetMatrix() {
    cin>>vexNum;
    for (int i = 0; i < vexNum; ++i) {
        for (int j = 0; j < vexNum; ++j) {
            cin>>Matrix[i][j];
        }
    }
}

void Map::BFS() {
    for (int i = 0; i < vexNum; ++i) {
        Visit[i]=0;
    }
    queue<int> que;
    for (int v = 0; v < vexNum; ++v) {
        if (!Visit[v]){
            Visit[v]=1;
            cout<<v<<" ";
            que.push(v);
            while (!que.empty()){
                int temp=que.front();
                que.pop();
                for (int i = 0; i < vexNum; ++i) {
                    if (Matrix[i][temp]==1 && Visit[i]==0){
                        cout<<i<<" ";
                        Visit[i]=1;
                        que.push(i);
                    }
                }
            }
        }
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        Map m;
        m.SetMatrix();
        m.BFS();
    }
}