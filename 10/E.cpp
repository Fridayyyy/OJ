#include <iostream>
#include <vector>
using namespace std;

class Map{
    vector<vector<int>> matrix;
    int m,n;
    int sum=0;
    void make(int x,int y){
        if (x<0||y<0||x>=m||y>=n||matrix[x][y]==1){
            return;
        }
        matrix[x][y]=1;
        make(x-1,y);
        make(x+1,y);
        make(x,y-1);
        make(x,y+1);
    }
public:
    void create();
    int getSum();
    void make();
};

void Map::make() {
    for (int i = 0; i < n; ++i) {
        make(0,i);
        make(m-1,i);
    }
    for (int i = 0; i < m; ++i) {
        make(i,0);
        make(i,n-1);
    }
}

void Map::create() {
    cin>>m>>n;
    matrix=vector<vector<int>>(m,vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>matrix[i][j];
        }
    }
}

int Map::getSum() {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j]==0)
                sum++;
        }
    }
    return sum;
}


int main(){
    int t;
    cin>>t;
    while (t--){
        Map map;
        map.create();
        map.make();
        cout<<map.getSum()<<endl;
    }
}