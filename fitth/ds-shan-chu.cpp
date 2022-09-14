//
// Created by 86184 on 2022/9/14.
//
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(){
        this->val=-1;
        this->next= nullptr;
    }
    Node(int num){
        this->val=num;
        this->next= nullptr;
    }
};

class List{
    Node* head;
    int size;

public:
    unordered_set<int> hashSet;
    List();
    ~List();
    void insert(int val);
    int getSize();
    void display();
};

List::List() {
    this->size=0;
    this->head=new Node();
}
List::~List() {

}
void List::insert(int val) {
    if (hashSet.count(val)){
        return;
    }
    hashSet.insert(val);
    Node* temp=head;
    while (temp->next){
        temp=temp->next;
    }
    temp->next=new Node(val);
    this->size++;
}
int List::getSize() {
    return this->size;
}

void List::display() {
    Node* temp=head->next;
    cout<<getSize()<<":";
    while (temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int m;
        cin>>m;
        List *list=new List;
        for (int j = 0; j < m; ++j) {
            int val;
            cin>>val;
            list->insert(val);
        }
        list->display();
    }
}