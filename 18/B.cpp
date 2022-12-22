#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Node{
public:
    int first;
    int second;
    int index;
    Node(){
        first=second=index=0;
    }
    Node(int f,int s,int i){
        first=f;
        second=s;
        index=i;
    }
};

class Sort{
    int n;
    map<int,vector<int>> maps;
public:
    Sort(int t){
        n=t;

        for (int i = 0; i < n; ++i) {
            int o,p;
            cin>>o>>p;
            if (maps.find(o)==maps.end()){
                vector<int> vec;
                maps.insert({o,vec});
            }
            maps.at(o).emplace_back(p);

        }
    }
    void main(){
        for (auto & i : maps) {
            int size=i.second.size();
//            cout<<size<<endl;
            for (int j = 0; j < size; ++j) {
                cout<<i.first<<" "<<i.second.at(j)<<endl;
            }
        }
    }
};

int main(){
    int t;
    while (cin>>t && t!=EOF){
        Sort s(t);
        s.main();
    }
}