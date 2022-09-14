//
// Created by 86184 on 2022/9/14.
//
#include <iostream>

using namespace std;

class Node{
public:
    Node* next;
    int val;

    Node(){
        this->val=-1;
        next= nullptr;
    }
    Node(int i){
        this->val=i;
        next= nullptr;
    }
};
class DList{
    Node* head;
    int size;
public:
    DList(int n);
    void del(Node* node);
    void insert(Node* node);
    ~DList();
    void helper();
};

DList::DList(int n) {
    this->size=n;
    this->head=new Node();
    Node* temp=head;

    for (int i = 0; i < n; ++i) {
        temp->next=new Node(n);
    }
    temp->next=head->next;
}

void DList::helper() {

}
DList::~DList() {

}

void DList::insert(Node *node) {

}

void DList::del(Node *node) {

}

int main(){
    int N,K,S;
    cin>>N>>K>>S;
    DList* dList=new DList(N);

}