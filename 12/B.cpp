#include <iostream>

using namespace std;

class Graph{
    int vexNum;
    int **matrix;
    bool *visited;
    int *in;
public:
    Graph(){
        cin>>vexNum;
        matrix=new int *[vexNum];
        for (int i = 0; i < vexNum; ++i) {
            matrix[i]=new int [vexNum];
            for (int j = 0; j < vexNum; ++j) {
                cin>>matrix[i][j];
            }
        }

        visited=new bool[vexNum];
        for (int i = 0; i < vexNum; ++i) {
            visited[i]= false;
        }

        in=new int[vexNum];
        for (int i = 0; i < vexNum; ++i) {
            int sum=0;
            for (int j = 0; j < vexNum; ++j) {
                sum+=matrix[j][i];
            }
            in[i]=sum;
        }
    }
    void display(){
        for (int i = 0; i < vexNum; ++i) {
            for (int j = 0; j < vexNum; ++j) {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    int SelectMin(){
        //int min=INT_MAX;
        for (int i = 0; i < vexNum; ++i) {
            if (!visited[i] && in[i] == 0){
                //min=i;
                return i;
            }
        }
        return -1;
    }
    void TP(){
        for (int i = 0; i < vexNum; ++i) {
            Sort();
            //display();
        }
    }
    void Sort(){
        int temp=SelectMin();
        visited[temp]=true;
        cout<<temp<<" ";
        for (int i = 0; i < vexNum; ++i) {
            matrix[temp][i]=0;
        }
        for (int i = 0; i < vexNum; ++i) {
            int sum=0;
            for (int j = 0; j < vexNum; ++j) {
                sum+=matrix[j][i];
            }
            in[i]=sum;
            //cout<<in[i]<<" ";
        }
        //cout<<endl;
    }
};

int main(){
    int t;
    cin>>t;
    while (t--){
        Graph graph;
        graph.TP();
        cout<<endl;
    }
}