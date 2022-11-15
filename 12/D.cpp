#include <iostream>

using namespace std;
#define MAX 99999

class Graph{
    int vexNum;
    int arcNum;
    bool *visited;
    int **matrix;

    int over(){
        for (int i = 0; i < vexNum; ++i) {
            if (!visited[i])
                return false;
        }
        return true;
    }
public:
    explicit Graph(int v){
        vexNum=v;

        matrix=new int *[vexNum];
        visited=new bool [vexNum];
        for (int i = 0; i < vexNum; ++i) {
            visited[i]= false;
        }

        for (int i = 0; i < vexNum; ++i) {
            matrix[i]=new int[vexNum];
            for (int j = 0; j < vexNum; ++j) {
                cin>>matrix[i][j];
                if (matrix[i][j]==0)
                    matrix[i][j]=MAX;
            }
        }

        int n;
        cin>>n;
        while (n--){
            int a,b;
            cin>>a>>b;
            matrix[a-1][b-1]=0;
            matrix[b-1][a-1]=0;
        }
    }
    void Prim(){
        int v=0;
        visited[v]= true;
        int minWeight=0;
        while (!over()){
            int min=MAX,temp=-1;
            for (int i = 0; i < vexNum; ++i) {

                if (visited[i]){
                    for (int j = 0; j < vexNum; ++j) {
                        if (!visited[j]&&matrix[i][j]<min){
                            temp=j;
                            min=matrix[i][j];
                        }
                    }
                }
            }
            visited[temp]=true;
            minWeight+=min;
        }

        cout<<minWeight<<endl;
    }
};

int main(){
    int t;
    while (cin>>t){
        Graph g(t);
        g.Prim();
    }
}
