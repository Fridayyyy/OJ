#include <iostream>

using namespace std;

class Sort{
    int n;
    string *strArr;
    string *str;
public:
    Sort(){
        cin>>n;
        strArr=new string[n];
        str=new string[n];
        for (int i = 0; i < n; ++i) {
            cin>>strArr[i];
            str[i]=strArr[i];
        }
        //display();
    }

    void sort(){
        int gap=1,num=n;
        int i,j;
        while (num>1){
            i=0;
            j=gap;

            while (j<n){
                merge(i,j,gap);
                num--;
                i+=gap*2;
                j+=gap*2;
            }
            gap*=2;
            display();
        }
    }

    void merge(int i,int j,int g){
        int a,b,c;
        for (a=i,b=j,c=i;a<i+g && b<j+g && b<n;c++) {
            if (strArr[a]>strArr[b]){
                str[c]=strArr[a++];
            } else
                str[c]=strArr[b++];
        }
        while (a<i+g){
            str[c++]=strArr[a++];
        }
        while (b<j+g && b<n){
            str[c++]=strArr[b++];
        }
        update();
    }
    void display(){
        for (int i = 0; i < n; ++i) {
            cout<<str[i];
            if (i!=n-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    void update(){
        for (int i = 0; i < n; ++i) {
            strArr[i]=str[i];
        }
    }
    void main(){
        sort();
    }
};



int main(){
    int t;
    cin>>t;
    while (t--){
        Sort s;
        s.main();
        if (t>0)
            cout<<endl;
    }
}