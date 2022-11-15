#include <iostream>

using namespace std;
#define MAX 99999

class Graph{
    int vexNum;
    int **matrix;
    string start;
    string *path;
    string *vexes;
    bool *visited;

    int min;
    int current;
    int *dest;

    void findMin(){
        min=MAX;
        current=-1;
        for (int i = 0; i < vexNum; ++i) {
            if (!visited[i]&&min>dest[i]){
                current=i;
                min=dest[i];
            }
        }
    }

    void display(){
        for (int i = 1; i < vexNum; ++i) {
            cout<<vexes[0]<<"-"<<vexes[i];
            if (dest[i] >= MAX)
            {
                cout << "--1" << endl;
                continue;
            }
            cout << "-" << dest[i] << "----[" << path[i] << "]" << endl;

        }
    }
    int Index(const string& str){
        for (int i = 0; i < vexNum; ++i) {
            if (vexes[i]==str)
                return i;
        }
        return -1;
    }


public:
    Graph(){
        cin>>vexNum;

        vexes=new string[vexNum];
        path=new string[vexNum];
        visited=new bool[vexNum];
        dest=new int[vexNum];

        for (int i = 0; i < vexNum; ++i) {
            visited[i]= false;
        }

        for (int i = 0; i < vexNum; ++i) {
            cin>>vexes[i];
        }

        matrix=new int*[vexNum];
        for (int i = 0; i < vexNum; ++i) {
            matrix[i]=new int[vexNum];
            for (int j = 0; j < vexNum; ++j) {
                cin>>matrix[i][j];
                if (matrix[i][j]==0){
                    matrix[i][j]=MAX;
                }
            }
        }

        cin>>start;
    };

    void DJ(){

        int index= Index(start);

        for (int i = 0; i < vexNum; ++i) {
            path[i]=start+" ";
            dest[i]=matrix[index][i];
        }

        dest[index]=0;
        visited[index]= true;

        for (int i = 0; i < vexNum - 1; ++i) {
            findMin();

            if (current!=-1){
                visited[current]= true;
                path[current]+=vexes[current]+" ";
                for (int j = 0; j < vexNum; ++j) {
                    if (!visited[j]&&(min+matrix[current][j])<dest[j]){
                        dest[j]=min+matrix[current][j];
                        path[j]=path[current];
                    }
                }
            }
        }
        display();
    }
};

int main(){
    int t;
    cin>>t;
    while (t--){
        Graph graph;
        graph.DJ();
    }
}