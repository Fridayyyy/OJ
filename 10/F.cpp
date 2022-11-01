#include <iostream>

const int maxLen=20;

using namespace std;
class Graph{
    int vexNum;
    int count;
    int arcNum;
    int **array;
    bool *visit;
    string *vex;
    int index(string str);
    void DFS(int v);
public:
    void getConnect();
    void display();
    void createGraph();
};

void Graph::DFS(int v) {
    if (!visit[v]){
        visit[v]= true;
        for (int i = 0; i < vexNum; ++i) {
            if (array[v][i]==1)
                DFS(i);
        }
    }
}

void Graph::getConnect() {
    for (int i = 0; i < vexNum; ++i) {
        if (!visit[i]){
            DFS(i);
            count++;
        }
    }
}
int Graph::index(std::string str) {
    for (int i = 0; i < vexNum; ++i) {
        if (vex[i]==str)
            return i;
    }
    return -1;
}

void Graph::display() {
    for (int i = 0; i < vexNum; ++i) {
        cout<<vex[i];
        if (vexNum-1==i){
            cout<<endl;
        } else
            cout<<" ";
    }
    for (int i = 0; i < vexNum; ++i) {
        for (int j = 0; j < vexNum; ++j) {
            cout<<array[i][j];
            if (j==vexNum-1){
                cout<<endl;
            } else
                cout<<" ";
        }
    }
    cout<<count<<endl<<endl;
}
void Graph::createGraph() {
    count=0;
    cin>>vexNum;
    vex=new string [vexNum];
    for (int i = 0; i < vexNum; ++i) {
        cin>>vex[i];
    }
    array=new int*[vexNum];
    visit=new bool[vexNum];
    for (int i = 0; i < vexNum; ++i) {
        visit[i]= false;
        array[i]=new int[vexNum];
        for (int j = 0; j < vexNum; ++j) {
            array[i][j]=0;
        }
    }
    cin>>arcNum;
    for (int i = 0; i < arcNum; ++i) {
        string str1,str2;
        cin>>str1>>str2;
        int num1= index(str1);int num2= index(str2);
        array[num1][num2]=1;
        array[num2][num1]=1;
    }
}

int main(){
    int t;
    cin>>t;
    while (t--){
        Graph graph;
        graph.createGraph();
        graph.getConnect();
        graph.display();
    }
}