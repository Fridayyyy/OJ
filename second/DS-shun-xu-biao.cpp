//
// Created by 常贵杰 on 2022/9/1.
//
#include <iostream>
using namespace std;
#define ok 0;
#define error -1;

class SeqList{
private:
    int *list;
    int maxsize;
    int size;

public:
    SeqList();
    ~SeqList();
    int list_size();
    int list_insert(int i,int item);
    int list_del(int i);
    int list_get(int i);
    void list_display();
};
SeqList::SeqList() {
    maxsize = 1000;
    size=0;
    list=new int[maxsize];
}
SeqList::~SeqList() {
    delete []list;
}
int SeqList::list_size() {
    return this->size;
}
int SeqList::list_insert(int i, int item) {
    for (int j = this->size; j > i-1; --j) {
        this->list[j]=this->list[j-1];
    }
    this->list[i-1]=item;
    this->size++;
}
int SeqList::list_del(int i) {
    if (i>this->size||i<=0)
        return error;
    for (int j = i-1; j < this->size; ++j) {
        this->list[j]=this->list[j+1];
        if(j== this->size-1){
            this->list[j]=-1;
        }
    }
    this->size--;
    return ok;
}
int SeqList::list_get(int i) {
    if (this->size<i||i<=0)
        return error;
    return this->list[i-1];
}
void SeqList::list_display() {
    for (int i = 0; i < size; ++i) {
        cout<<to_string(list[i])+" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    SeqList* seq=new SeqList();
    for (int i = 0; i < n; ++i) {
        int val;
        cin>>val;
        seq->list_insert(i+1,val);
    }
    cout<<to_string(seq->list_size())+" ";
    seq->list_display();

    int a,b,c,d,e,f,g,h;
    cin>>a>>b;
    seq->list_insert(a,b);
    cout<<to_string(seq->list_size())+" ";
    seq->list_display();

    cin>>c>>d;
    seq->list_insert(c,d);
    cout<<to_string(seq->list_size())+" ";
    seq->list_display();

    //删除
    cin>>e;

    if (seq->list_del(e)==-1)
        cout<<"error"<<endl;
    else{
        cout<<to_string(seq->list_size())+" ";
        seq->list_display();
    }


    //删除
    cin>>f;
    if (seq->list_del(f)==-1){
        cout<<"error"<<endl;
    } else{
        cout<<to_string(seq->list_size())+" ";
        seq->list_display();
    }

    //查找
    cin>>h;
    if (seq->list_get(h)==-1){
        cout<<"error"<<endl;
    } else
        cout<<seq->list_get(h)<<endl;

    //查找
    cin>>g;
    if(seq->list_get(g)==-1)
        cout<<"error"<<endl;
    else
        cout<<seq->list_get(g)<<endl;
}