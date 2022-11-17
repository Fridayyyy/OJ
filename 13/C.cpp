#include <iostream>

using namespace std;

class IndexTable{
public:
    int start;
    int end;
    int key;
};
class Array{
    int len;
    int *arr;
    int tableNum;
    IndexTable *tables;
    int tableSize;
public:
    Array(){
        cin>>len;
        arr=new int[len];
        for (int i = 0; i < len; ++i) {
            cin>>arr[i];
        }
    }
    void Index(){
        cin>>tableNum;
        tables=new IndexTable[tableNum];

        tableSize=len/tableNum;


        for (int i = 0; i < tableNum; ++i) {
            cin>>tables[i].key;
            tables[i].start=tableSize*i;
            tables[i].end=tableSize*(i+1)-1;

            //cout<<tables[i].key<<" "<<tables[i].start<<endl;
        }
    }

    void F(){
        int t;
        cin>>t;
        while (t--){
            int n;
            cin>>n;
            if (find(n)==-1){
                cout<<"error"<<endl;
            }
//            else{
//                cout<<find(n)<<endl;
//            }

        }
    }
    int find(int n){
        int t=1;
        if (tables[0].key>=n){

        } else{
            for (int i = 1; i < tableNum; ++i) {
                t++;
                if (tables[i-1].key<n && n<=tables[i].key){
                    break;
                }
            }
        }
        t--;
        for (int i = tables[t].start; i < tableSize*(t+1) && i<=len; ++i) {
            t++;
            if (arr[i]==n){
                cout<<i+1<<"-"<<t+1<<endl;
                return i+t;
            }
        }
        return -1;
    }

    void main(){
        Index();
        F();
    }
};

int main(){
    Array a;
    a.main();
}