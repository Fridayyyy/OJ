#include <iostream>

using namespace std;

class Hash{
    int* vec;
    int size;
    int count;
public:
    Hash(){
        cin>>size>>count;
        vec=new int[size];
        for (int i = 0; i < size; ++i) {
            vec[i]=-1;
        }
    }
    int getHash(int n){
        return n % 11;
    }
    void insert(int n,int hash){
        hash%=size;
        if (vec[hash]!=-1){
            insert(n,hash+1);
        } else{
            vec[hash]=n;
        }
    }
    void search(int n){
        int a=0;
        int hash= getHash(n);
        while (1){
            a++;
            hash%=size;
            if (vec[hash]==n){
                cout<<'1'<<" "<<a<<" "<<hash+1<<endl;
                break;
            } else if (vec[hash]==-1){
                cout<<'0'<<" "<<a<<endl;
                break;
            }
            hash++;
        }
    }
    void display(){
        for (int i = 0; i < size-1; ++i) {
            if (vec[i]!=-1){
                cout<<vec[i]<<" ";
            } else{
                cout<<"NULL"<<" ";
            }
        }
        if (vec[size-1]==-1){
            cout<<"NULL";
        } else if (vec[size-1]!=-1){
            cout<<vec[size-1];
        }
        cout<<endl;
    }
    void main(){
        int num;
        for (int i = 0; i < count; ++i) {
            cin>>num;
            int hash= getHash(num);
            insert(num,hash);
        }

        display();

        int n;
        cin>>n;
        while (n--){
            cin>>num;
            search(num);
        }
    }
};



int main(){
    int t;
    cin>>t;
    while (t--){
        Hash hash;
        hash.main();
    }
}