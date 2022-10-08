#include<iostream>
#include<string>
#include <vector>
using namespace std;
vector<int> nextT(10000);
void Get_next(string a){
    int i=0,j=-1;
    nextT[0]=-1;
    int size=a.size();

    while (i<size){
        if (j==-1||a[i]==a[j]){
            i++;j++;
        } else{
            j=nextT[j];
        }
    }
    for (auto k=nextT.begin();k!=nextT.end();k++) {
        cout<<*k<<" "<<endl;
    }
    cout<<endl;
}

int KMP(string a,string b){
    int i=0,j=0;
    Get_next(b);
    int size1=a.size(),size2=b.size();

    while (i<size1&&j<size2){
        if (j==-1||a.at(i)==b.at(j)){
            i++;j++;
        } else{
            j=nextT[j];
        }
    }
    if (j==size1){
        return i-j+1;
    }
    return 0;
}
int main()
{
    string a,b;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        cout<<KMP(a,b)<<endl;
    }
    return 0;
}
