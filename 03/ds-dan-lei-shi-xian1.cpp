//
// Created by 常贵杰 on 2022/9/8.
//
#include <iostream>

#define ok 0;
#define error -1;
struct Node{
public:
    int data;
    Node* next;
    Node():data(-1),next(nullptr){}
    Node(int i):data(i),next(nullptr){}
    Node(int i,Node* next):data(i),next(next){}
};

class LinkList{
public:
    Node* head;
    int len;
    LinkList();
    ~LinkList();
    Node* LL_index(int i);
    int LL_get(int i);
    int LL_insert(int i,int item);
    int LL_del(int i);
    void LL_display();
};
LinkList::LinkList() {
    head=new Node();
    len=0;
}
LinkList::~LinkList() {
    Node *p,*q;
    p=head;
    while (p){
        q=p;
        p=p->next;
        delete q;
    }
    len=0;
    head= nullptr;
}
Node* LinkList::LL_index(int i) {
    if(len<i){
        return nullptr;
    }
    Node* res=head->next;
    for (int j = 1; j < i; ++j) {
        res=res->next;
    }
    return res;
}
int LinkList::LL_get(int i) {
    return LL_index(i)->data;
}

int LinkList::LL_insert(int i, int item) {
    if (len+1<i){
        return error;
    }
    Node* temp=head;

    for (int j = 1; j < i; ++j) {
        temp=temp->next;
    }
    Node *node=new Node(item);

    if (temp->next){
        node->next=temp->next;
    }
    temp->next=node;
    len++;
    return ok;
}
int LinkList::LL_del(int i) {
    if (len<i)
        return error;
    Node* temp=head;
    for (int j = 1; j < i; ++j) {
        temp=temp->next;
    }

    if (temp->next->next){
        temp->next=temp->next->next;
    } else{
        temp->next= nullptr;
    }

    len--;
    return error;
}
void LinkList::LL_display() {
    Node* p;
    p=head->next;
    while (p){
        std::cout<<p->data<<" ";
        p=p->next;
    }
    std::cout<<std::endl;
}
int main(){
    int n;
    std::cin>>n;
    auto head=new LinkList;
    auto temp=head;

    for (int i = 1; i < n+1; ++i) {
        int val;
        std::cin>>val;
        temp->LL_insert(i,val);
    }
    head->LL_display();

    //第一次插入
    int p,q,val1,val2;
    std::cin>>p>>val1;
    if (p>head->len+1){
        std::cout<<"error"<<std::endl;
    } else{
        head->LL_insert(p,val1);
        head->LL_display();
    }
    //第二次插入
    std::cin>>q>>val2;
    if (q>head->len+1){
        std::cout<<"error"<<std::endl;
    } else{
        head->LL_insert(q,val2);
        head->LL_display();
    }

    //删除1
    int d1,d2;
    std::cin>>d1;
    if (d1>head->len||d1<=0){
        std::cout<<"error"<<std::endl;
    } else{
        head->LL_del(d1);
        head->LL_display();
    }
    //删除2
    std::cin>>d2;
    if (d2>head->len||d2<=0){
        std::cout<<"error"<<std::endl;
    } else{
        head->LL_del(d2);
        head->LL_display();
    }

    //查找1
    int s1,s2;
    std::cin>>s1;
    if (s1>head->len||s1<=0){
        std::cout<<"error"<<std::endl;
    } else{
        std::cout<<head->LL_get(s1)<<std::endl;
    }
    //查找2
    std::cin>>s2;
    if (s2>head->len||s2<=0){
        std::cout<<"error"<<std::endl;
    } else{
        std::cout<<head->LL_get(s2)<<std::endl;
    }
    return 0;
}

