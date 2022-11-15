#include <iostream>

using namespace std;
#define MAX 9999
class Node{
public:
    string data;
    int weight;
};

class Graph{

    int vexNum;
    string startPos;
//    int edgeNum;

    string *vexes;
    int **matrix;
    string *nodes;
    bool *visited;
    int minWeight;


    int Index(string str){
        for (int i = 0; i < vexNum; ++i) {
            if (vexes[i]==str)
                return i;
        }
        return -1;
    }
    bool over(){
        for (int i = 0; i < vexNum; ++i) {
            if (!visited[i])
                return false;
        }
        return true;
    }
public:

    Graph(){
        minWeight=0;
        cin>>vexNum;
        vexes=new string[vexNum];
        for (int i = 0; i < vexNum; ++i) {
            cin>>vexes[i];
        }

        visited=new bool [vexNum];
        matrix=new int *[vexNum];
        for (int i = 0; i < vexNum; ++i) {
            visited[i]= false;
            matrix[i]=new int[vexNum];
            for (int j = 0; j < vexNum; ++j) {
                matrix[i][j]=MAX;
            }
        }

        int arcNum;
        cin>>arcNum;
        for (int i = 0; i < arcNum; ++i) {
            string str1,str2;
            int w;
            cin>>str1>>str2>>w;
            int index1=Index(str1);
            int index2= Index(str2);

            matrix[index1][index2]=w;
        }

        cin>>startPos;
    }
    void Prim(){
        int v=0;
        visited[v]=true;
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
    void Kruskal(){

    }
};

int main(){
    Graph graph;
    graph.Prim();
    //graph.Kruskal();
}