#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 9999
class Edge{
public:
    string start,end;
    int weight;
    Edge(){
        start="";
        end="";
        weight=0;
    }
    Edge(string s,string e,int w){
        start=s;
        end=e;
        weight=w;
    }
};

bool compare(Edge a,Edge b){
    return a.weight<b.weight;
}

class Graph{

    int vexNum;
    string startPos;

    vector<Edge> edges;
    vector<int> father;
    vector<Edge> result;
    queue<Edge*> edge;

    string *vexes;
    int **matrix;
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

        edges=vector<Edge>(arcNum);
        for (int i = 0; i < arcNum; ++i) {
            string str1,str2;
            int w;
            cin>>str1>>str2>>w;
            int index1=Index(str1);
            int index2= Index(str2);

            matrix[index1][index2]=w;
            matrix[index2][index1]=w;

            if (str1<str2){
                edges[i].start=str1;
                edges[i].end=str2;
            } else{
                edges[i].start=str2;
                edges[i].end=str1;
            }
            edges[i].weight=w;
        }

        cin>>startPos;
    }
    void Prim(){
        int v= Index(startPos);
        visited[v]=true;
        while (!over()){
            int min=MAX,start=-1,end=-1;
            for (int i = 0; i < vexNum; ++i) {
                if (visited[i]){
                    for (int j = 0; j < vexNum; ++j) {
                        if (!visited[j]&&matrix[i][j]<min){
                            start=i;
                            end=j;
                            min=matrix[i][j];
                        }
                    }
                }
            }
            Edge* e=new Edge(vexes[start],vexes[end],min);
            edge.push(e);
            visited[end]=true;
            minWeight+=min;
        }
        cout<<minWeight<<endl;
        cout<<"prim:"<<endl;


        while (!edge.empty()){
            cout<<edge.front()->start<<" "<<edge.front()->end<<" "<<edge.front()->weight<<endl;
            edge.pop();
        }

    }



    int findF(int a){
        while (a!=father[a]){
            a=father[a];
        }
        return a;
    }
    void Kruskal(){
        father.resize(vexNum);
        sort(edges.begin(),edges.end(), compare);
        for (int i = 0; i < vexNum; ++i) {
            father[i]=i;

        }
        for (int i = 0; i < edges.size()&&result.size()<vexNum-1; ++i) {
            string s=edges[i].start;
            string e=edges[i].end;
            if (findF(Index(s))!= findF(Index(e))){
                result.push_back(edges[i]);
                father[findF(Index(s))]=father[findF(Index(e))];
            }

        }
        cout<<"kruskal:"<<endl;
        for (auto & i : result) {
            cout<<i.start<<" "<<i.end<<" "<<i.weight<<endl;
        }

    }
};

int main(){
    Graph graph;
    graph.Prim();
    graph.Kruskal();
}