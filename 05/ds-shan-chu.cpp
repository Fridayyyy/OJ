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
    void display(int i,int n);
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

void List::display(int i,int n) {
    Node* temp=head->next;
    cout<<getSize()<<": ";
    while (temp){
        if (!temp->next){
            cout<<temp->val;
        } else{
            cout<<temp->val<<" ";
        }

        temp=temp->next;
    }
    if (i<n){
        cout<<"\n";
    }

}


int main(){
    int n;
    cin>>n;

    vector<vector<int>> vectors;


    for (int i = 0; i < n; ++i) {

        vector<int> vec;
        int num;
        while (cin>>num){
            vec.push_back(num);
            char ch=getchar();
            if (ch=='\n'){
                break;
            }
        }
        vectors.push_back(vec);

    }
    for (int i = 0; i < vectors.size(); ++i) {
        List* list=new List;
        for (int j = 1; j < vectors[i].size(); ++j) {
            list->insert(vectors[i].at(j));
        }
        list->display(i+1,n);
    }
}