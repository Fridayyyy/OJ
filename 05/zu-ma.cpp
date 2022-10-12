//
// Created by 86184 on 2022/9/14.
//
#include <vector>
#include <iostream>
#include <string>

#define ok 0
#define error -1

using namespace std;
class Node{
public:
    Node* prev;
    Node* next;
    char ch;

    explicit Node(char c){
        ch=c;
        prev= nullptr;
        next= nullptr;
    }
    Node(char c,Node *p,Node *q){
        ch=c;
        next=p;
        prev=q;
    }
};

class List{
public:
    Node* head;
    int size;
    List();
    explicit List(string str);
    ~List();
    int helper();
    void insert(int i,char ch);
    void del(int i);
    void display();
    Node* index(int i);

};
List::List() {
    head= new Node(0);
    size=0;
}
List::List(string str) {
    size=str.size();
    head=new Node(0);
    Node* temp=head;
    for (char i : str) {
        Node* node=new Node(i);
        temp->next=node;
        node->prev=temp;
        temp=temp->next;
    }

}
void List::insert(int i,char ch) {
    size++;
    if (size==1){
        Node* node1=new Node(ch, nullptr,head);
        head->next=node1;
        return;
    }
    Node* node= index(i);
    Node* beforeNode= index(i-1);
    Node* temp=new Node(ch,node,beforeNode);
    beforeNode->next=temp;
    temp->next->prev=temp;
}
void List::del(int i) {
    size--;
    Node* before= index(i-1);
    Node* node= index(i);
    Node* temp=node;

    before->next=node->next;

    if (node->next){
        node->next->prev=before;
    }
    delete temp;
}

Node *List::index(int i) {
    if (i<0)
        return nullptr;
    Node *node=head;
    for (int j = 0; j < i; ++j) {
        node=node->next;
    }
    return node;
}
int List::helper(){
    Node* p=head->next;
    int index=1;
    while (p){
        int count=1;
        Node* cur=p->next;
        while (cur&&p->ch==cur->ch){
            count++;
            cur=cur->next;
        }
        if (count>=3){
            for (int i = 0,j=index; i < count; ++i) {
                del(j);
            }
            return ok;
        }

        index++;
        p=p->next;
    }
    return error;
}

void List::display() {
    Node* temp=head->next;
    if (!temp){
        cout<<"-"<<endl;
        return;
    }
    while (temp){
        cout<<temp->ch;
        temp=temp->next;
    }
    cout<<endl;
}
List::~List() {}
int main(){
    string  str;
    cin>>str;

    List* list=new List(str);

    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int j;
        char ch;
        cin>>j>>ch;
        list->insert(j+1,ch);
        while (1){
            if (list->helper()!=ok)
                break;
        }
        list->display();
    }
}