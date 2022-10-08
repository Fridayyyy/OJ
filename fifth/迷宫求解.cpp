//
// Created by 86184 on 2022/9/23.
//
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct position{
    int x,y;
};

int main(){
    int t,n;
    cin>>t;
    while (t--){
        stack<position> path;
        cin>>n;
        vector<vector<int>> maze(n,vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin>>maze[i][j];
            }
        }
        if (maze[0][0]==1){
            cout<<"no path"<<endl;
            continue;
        }
        path.push({0,0});
        maze[0][0]=1;
        int i=0,j=0;

        while (1){
            if (j+1<n && maze[i][j+1]==0){
                maze[i][j+1]=1;
                path.push({i,++j});
            } else if (i+1<n && maze[i+1][j]==0){
                maze[i+1][j]=1;
                path.push({++i,j});
            } else if (j-1>=0&&maze[i][j-1]==0){
                maze[i][j-1]=1;
                path.push({i,--j});
            } else if (i-1>=0 && maze[i-1][j]==0){
                maze[i-1][j]=1;
                path.push({--i,j});
            } else{
                path.pop();
                if (!path.empty()){
                    i=path.top().x;
                    j=path.top().y;
                }
            }
            if (path.empty()||(i==n-1 && j==n-1)){
                break;
            }
        }

        if (path.empty()){
            cout<<"no path"<<endl;
        } else{
            stack<position> path1;
            while (!path.empty()){
                path1.push(path.top());
                path.pop();
            }
            i=0;
            while (!path1.empty()) {
                if ((++i) % 4 == 0) {
                    cout << '[' << path1.top().x << ',' << path1.top().y << ']' << "--" << endl;
                } else {
                    cout << '[' << path1.top().x << ',' << path1.top().y << ']' << "--";
                }
                path1.pop();
            }
            cout << "END" << endl;
        }
    }
}
