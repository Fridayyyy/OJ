//
// Created by 常贵杰 on 2022/9/1.
//
#include <iostream>
#include <queue>

using namespace std;
class List{
private:
    int size;
    int *nums;
public:
    List(int size);
    ~List();
    int getSize();
    void print();
    void add(queue<int> nums1,queue<int> nums2);
};
List::List(int size) {
    this->size=size;
    this->nums=new int[size];
}
List::~List() {
    //delete []nums;
}
void List::print() {
    for (int i = 0; i < this->size; ++i) {
        cout<<this->nums[i]<<" ";
    }
    cout<<endl;
}

int List::getSize() {
    return this->size;
}

void List::add(queue<int> nums1,queue<int> nums2) {
    for (int i = 0; i < this->size; ++i) {
        if(nums1.front()<nums2.front()&&!nums1.empty()&&!nums2.empty()){
            this->nums[i]=nums1.front();
            nums1.pop();
        } else {
            this->nums[i]=nums2.front();
            nums2.pop();
        }

    }
}

int main(){
    int m,n;
    cin>>m;
    queue<int> q1,q2;
    for (int i = 0; i < m; ++i) {
        int val;
        cin>>val;
        q1.push(val);
    }
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int val;
        cin>>val;
        q2.push(val);
    }
    List* list=new List(m+n);
    cout<<list->getSize()<<" ";
    list->add(q1,q2);

    list->print();
    return 0;
}