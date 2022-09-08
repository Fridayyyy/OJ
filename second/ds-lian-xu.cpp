//
// Created by 常贵杰 on 2022/9/1.
//
#include <iostream>
#include <vector>
using namespace std;

#define ok 0;
#define error -1;

class Seq{
private:
    vector<int> list;
public:
    Seq();
    ~Seq();
    void multiinsert(int i,vector<int>vec);
    void multidel(int i,int n);
    int getSize();
    void print();
};

Seq::Seq() {}
Seq::~Seq() {}
int Seq::getSize(){
    return this->list.size();
}
void Seq::print() {
    for (int i = 0; i < this->list.size(); ++i) {
        cout<<to_string(list[i])+" ";
    }
    cout<<endl;
}

void Seq::multiinsert(int i,vector<int>vec) {
    this->list.insert(list.begin()+i-1,vec.begin(),vec.end());
    //cout<<list.size()<<endl;
}

void Seq::multidel(int i, int n) {
    this->list.erase(this->list.begin()+i-1,this->list.begin()+i+n-1);
    //cout<<list.size()<<endl;
}
int main(){
    int n;
    cin>>n;
    Seq* seq=new Seq();
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        int num;
        cin>>num;
        nums.push_back(num);
    }
    seq->multiinsert(1,nums);
    cout<<seq->getSize()<<" ";
    seq->print();

    vector<int> insertNums;
    int p,len;
    cin>>p>>len;
    for (int i = 0; i < len; ++i) {
        int val;
        cin>>val;
        insertNums.push_back(val);
    }
    seq->multiinsert(p,insertNums);
    cout<<seq->getSize()<<" ";
    seq->print();

    int q,l;
    cin>>q>>l;
    seq->multidel(q,l);
    cout<<seq->getSize()<<" ";
    seq->print();
}