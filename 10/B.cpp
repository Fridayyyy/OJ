#include <iostream>

using namespace std;


class Graph{
    char type;
    int vexNum;
    int arcNum;
    string *vex;
    int **array;

    int *in;
    int *out;
public:
    Graph();
    void display();
    void degree();
    int index(string str);

};

Graph::Graph() {
    cin>>type>>vexNum;
    vex=new string[vexNum];
    for (int i = 0; i < vexNum; ++i) {
        cin>>vex[i];
    }
    array=new int *[vexNum];
    for (int i = 0; i < vexNum; ++i) {
        array[i]=new int[vexNum];
        for (int j = 0; j < vexNum; ++j) {
            array[i][j]=0;
        }
    }

    in=new int[vexNum];
    out=new int[vexNum];
    for (int i = 0; i < vexNum; ++i) {
        in[i]=0;
        out[i]=0;
    }
    cin>>arcNum;
    for (int i = 0; i < arcNum; ++i) {
        string str1,str2;
        cin>>str1>>str2;
        int pos1= index(str1);
        int pos2= index(str2);
        if (type=='U'){
            array[pos1][pos2]=1;
            array[pos2][pos1]=1;
        } else if (type=='D'){
            array[pos1][pos2]=1;
        }
    }

}

int Graph::index(string str) {
    for (int i = 0; i < vexNum; ++i) {
        if (vex[i]==str){
            return i;
        }
    }
    return -1;
}

void Graph::degree() {
    for (int i = 0; i < vexNum; ++i) {
        for (int j = 0; j < vexNum; ++j) {
            if (array[i][j]==1){
                out[i]++;
                in[j]++;
            }
        }
    }
}

void Graph::display() {
    for (int i = 0; i < vexNum; ++i) {
        for (int j = 0; j < vexNum; ++j) {
            cout<<array[i][j];
            if (vexNum-1==j)
                cout<<endl;
            else
                cout<<" ";
        }
    }
    for (int i = 0; i < vexNum; ++i) {
        cout<<vex[i];
        if (type=='D'){
            if (in[i]!=0 || out[i]!=0){
                cout<<": "<<out[i]<<" "<<in[i]<<" "<<out[i]+in[i]<<endl;
            } else
                cout<<endl;
        }
        if (type=='U'){
            if (out[i]!=0){
                cout<<": "<<in[i]<<endl;
            } else
                cout<<endl;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while (t--){
        Graph g;
        g.degree();
        g.display();
    }
}