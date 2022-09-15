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
public:
    explicit DList(int n);
    ~DList();
    void helper(int k,int s);
};

DList::DList(int n) {
    this->head=new Node();
    Node* temp=head;

    for (int i = 1; i < n+1; ++i) {
        temp->next=new Node(i);
        temp=temp->next;
    }
    temp->next=head->next;
}

void DList::helper(int k,int s) {
    Node* temp=head->next;
    while (temp){
        for (int i = 1; i < k+s-2; ++i) {
            temp=temp->next;
        }
        cout<<"temp.val:"<<temp->val<<endl;
        if (temp->val==temp->next->val){
            cout<<temp->val<<" ";
            temp= nullptr;
            cout<<"break"<<endl;
            break;
        }
        cout<<temp->next->val<<" "<<endl;
        temp->next=temp->next->next;
    }
}
DList::~DList() {

}

int main(){
    int N,K,S;
    cin>>N>>K>>S;
    DList* dList=new DList(N);
    dList->helper(K,S);
}