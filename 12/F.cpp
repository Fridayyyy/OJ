#include <iostream>
#include <vector>
using namespace std;

class Graph{
public:
    vector<bool> isFinished;
    vector<vector<int>> adjMat;
    int n;

    void readAdjMatrix(){
        cin>>n;
        adjMat=vector<vector<int>>(n,vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin>>adjMat[i][j];
            }
        }

        isFinished=vector<bool>(n, false);
//        for (int i = 0; i < n; ++i) {
//            cout<<isFinished[i]<<" ";
//        }
//        cout<<endl;
    }

    bool isZeroInDegrees(int vertexNo){
        for (int i = 0; i < n; ++i) {
            if (adjMat[i][vertexNo]>0){
                return false;
            }
        }
        return true;
    }

    int select() {
        for (int i = 0; i < n; ++i) {
            if (!isZeroInDegrees(i) || isFinished[i]) {
                continue;
            } else{
                isFinished[i]=true;
                return i;
            }
        }
        return -1;
    }

    void update(int rootNo){
        for (int i = 0; i < n; ++i) {
            adjMat[rootNo][i]=0;
        }
    }

    void topologySort(){
        for (int i = 0; i < n; ++i) {
            int root=select();
            if (root==-1)
                break;
            update(root);
            cout<<root<<" ";
        }
        cout<<endl;
    }

    void main(){
        readAdjMatrix();
        topologySort();
    }
};

int main(){
    int t;
    cin>>t;
    while (t--){
        Graph graph;
        graph.main();
    }
}