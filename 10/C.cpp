#include <iostream>

using namespace std;

const int MaxLen=20;
class Map{
    bool Visit[MaxLen];
    int Matrix[MaxLen][MaxLen];
    int VexNum;
    void DFS(int v);
public:
    void SetMatrix();
    void DFSTraverse();
};

void Map::SetMatrix() {
    cin>>VexNum;
    for (int i = 0; i < VexNum; ++i) {
        for (int j = 0; j < VexNum; ++j) {
            cin>>Matrix[i][j];
        }
    }
}

void Map::DFS(int v) {
    int w,k=0;
    Visit[v]=1;
    cout<<v<<" ";

    int *AdjVex=new int[VexNum];
    for (int i = 0; i < VexNum; ++i) {
        AdjVex[i]=-1;
    }
    for (int i = 0; i < VexNum; ++i) {
        if (Matrix[v][i]==1){
            AdjVex[k]=i;
            k++;
        }
    }

    int j=0;
    w=AdjVex[j];
    while (w!=-1){
        if (!Visit[w]){
            DFS(w);
        }
        j++;
        w=AdjVex[j];
    }

    delete [] AdjVex;
}

void Map::DFSTraverse() {
    for (int i = 0; i < VexNum; ++i) {
        Visit[i]= 0;
    }
    for (int i = 0; i < VexNum; ++i) {
        if (!Visit[i]){
            DFS(i);
        }
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        Map map;
        map.SetMatrix();
        map.DFSTraverse();
    }
}