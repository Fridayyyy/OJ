#include <iostream>

using namespace std;

const int maxLen=20;

class Graph{
    int vexNum;
    int matrix[maxLen][maxLen];
public:

    Graph(){
        cin>>vexNum;
        for (int i = 0; i < vexNum; ++i) {
            for (int j = 0; j < vexNum; ++j) {
                cin>>matrix[i][j];
            }
        }
    }
    void isLT(){
        for (int i = 0; i < vexNum; ++i) {
            for (int j = 0; j < vexNum; ++j) {
                if (matrix[i][j]==matrix[vexNum-1-i][vexNum-j-1])
                    continue;
                else
                    cout<<"No"<<endl;
                return;
            }
        }
        cout<<"Yes"<<endl;
    };
};

int main(){
    int t;
    cin>>t;
    while (t--){
        Graph graph;
        graph.isLT();
    }
}