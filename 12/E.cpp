#include <iostream>
#include <vector>
using namespace std;
#define MAX_DIS 0x7FFFFF

class Vertex{
public:
    int indexNo;//顶点索引号
    string label;//顶点的标签
    int distance;//顶点到远点距离
    bool isVisited;
    vector<int> path;

    Vertex(int indexNo,const string& label="",int distance=MAX_DIS){
        this->label=label;
        this->distance=distance;
        this->indexNo=indexNo;
        this->isVisited= false;
    }
    void updatePath(const vector<int>& prePath){
        this->path=prePath;
        this->path.push_back(this->indexNo);
    }
    void displayPath(vector<Vertex>& vertexes,int sourceNo){
        cout << vertexes[sourceNo].label;
        cout << "-";
        cout << this->label;

        cout << "-";
        if (this->distance >= MAX_DIS) {
            cout << "-1\n";
            return;
        }
        cout << this->distance;
        cout << "----";

        cout << "[";
        int i=0;
        int size = this->path.size();
        for(; i<size; ++i) {
            cout << vertexes[path[i]].label <<" ";
        }
        cout << "]";
        cout << endl;
    }

};

class Graph{
public:
    vector<Vertex> vertexes;
    vector<vector<int>> adjMat;

    int getNo(string &label){
        for (auto & vertexe : vertexes) {
            if (vertexe.label==label)
                return vertexe.indexNo;
        }
        return -1;
    }
    void readVertexes(){
        int n;
        cin>>n;
        for (int i = 0; i < n; ++i) {
            string label;
            cin>>label;

            Vertex v(i,label);
            this->vertexes.push_back(v);
        }
    }

    void readAdjMat(){
        int n= this->vertexes.size();
        for (int i = 0; i < n; ++i) {
            vector<int> row;
            for (int j = 0; j < n; ++j) {
                int dis;
                cin>>dis;
                row.push_back(dis);
            }
            adjMat.push_back(row);
        }
    }

    void update(int rootN){
        int n=vertexes.size();
        Vertex& root=vertexes[rootN];
        int rootDis=root.distance;

        for (int i = 0; i < n; ++i) {
            Vertex& v=vertexes[i];
            if (v.isVisited)
                continue;
            if (adjMat[rootN][i]==0)
                continue;

            int newDis=rootDis+ this->adjMat[rootN][i];
            if (newDis<v.distance){
                v.distance=newDis;
                v.updatePath(vertexes[rootN].path);
            }
        }
    }
    int select(){
        int minDis=MAX_DIS;
        int minNo=-1;

        int n=vertexes.size();
        for (int i = 0; i < n; ++i) {
            Vertex& v=vertexes[i];
            if (v.isVisited)
                continue;
            if (v.distance<minDis){
                minDis=v.distance;
                minNo=v.indexNo;
            }
        }
        if (minNo==-1)
            return -1;
        vertexes[minNo].isVisited=true;
        return minNo;
    }
    void readSourceNo(){
        string label;
        cin>>label;
        int sourceNo;
        sourceNo= getNo(label);

        Vertex& source=vertexes[sourceNo];
        source.isVisited=1;
        source.distance=0;
        source.path.push_back(sourceNo);
        update(sourceNo);

        int n=vertexes.size();
        for (int i = 0; i < (n-1); ++i) {
            int v=select();
            if (v==-1)
                break;
            update(v);
        }

        string sourceLabel=source.label;
        for (int i = 0; i < n; ++i) {
            if (i==sourceNo) continue;
            Vertex& v=vertexes[i];
            v.displayPath(vertexes,sourceNo);
        }
    }

    void main(){
        readVertexes();
        readAdjMat();
        readSourceNo();
    }
};

int main(){
    int t;
    cin>>t;
    while (t--){
        Graph g;
        g.main();
    }
}