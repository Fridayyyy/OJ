
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
    int n=0;
    Node* res;
    while (n-1!=i){
        res=head->next;
        n++;
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

    for (int j = 2; j < i; ++j) {
        head=head->next;
    }
    //Node *temp=head;
    Node *node=new Node(item);

    node->next=head->next;
    head->next=node;

    len++;
    return ok;
}
int LinkList::LL_del(int i) {
    if (len<i)
        return error;
    int n=0;
    while(n+1!=i){
        head=head->next;
        n++;
    }
    head->next=head->next->next;

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
        head->LL_insert(i,val);
    }
    temp->LL_display();

    return 0;
}

