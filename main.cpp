#include <iostream>
#include <vector>

using namespace std;
const int maxLen=20;
class Graph{
    float res=1.0;

    string str[maxLen];
    float matrix[maxLen][maxLen];
    int vexNum;
    int arcNum;
public:
    Graph(){
        cin>>vexNum>>arcNum;
        //初始化
        for (int i = 0; i < vexNum; ++i) {
            for (int j = 0; j < vexNum; ++j) {
                matrix[i][j]=0.0;
            }
        }
        for (int i = 0; i < vexNum; ++i) {
            cin>>str[i];
        }

        for (int i = 0; i < arcNum; ++i) {
            string str1,str2;
            float H;
            cin>>str1>>H>>str2;
            for (int j = 0; j < vexNum; ++j) {
                if (str[j]==str1){
                    for (int k = 0; k < vexNum; ++k) {
                        if (str[k]==str2){
                            matrix[j][k]=H;
                        }
                    }
                }
            }
        }

    }
    void count(){
        for (int i = 0; i < vexNum; ++i) {
            for (int j = 0; j < vexNum; ++j) {
                if (matrix[i][j]>0.0)
                    res*=matrix[i][j];
            }
        }
        if (res>1.0){
            cout<<"YES"<<endl;
        } else{
            cout<<"NO"<<endl;
        }
    }
};

int main(){
    int t;
    cin>>t;
    while (t--){
        Graph graph;
        graph.count();
    }
}