//
// Created by 常贵杰 on 2022/9/8.
//
/*
 * 201905100201
输入
        n
第1行先输入n表示有n个数据，接着输入n个数据
        第2行输入要插入的位置和新数据
第3行输入要插入的位置和新数据
        第4行输入要删除的位置
第5行输入要删除的位置
        第6行输入要查找的位置
第7行输入要查找的位置

        输出
n
        数据之间用空格隔开，

第1行输出创建后的单链表的数据

        每成功执行一次操作（插入或删除），输出执行后的单链表数据

        每成功执行一次查找，输出查找到的数据

        如果执行操作失败（包括插入、删除、查找等失败），输出字符串error，不必输出单链表


6 11 22 33 44 55 66
3 777
1 888
1
11
0
5

11 22 33 44 55 66
11 22 777 33 44 55 66
888 11 22 777 33 44 55 66
11 22 777 33 44 55 66
error
error
44


        */
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

