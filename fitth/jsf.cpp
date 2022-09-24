//
// Created by 86184 on 2022/9/16.
//
#include <iostream>
using namespace std;

class ListNode
{
    int data;
    ListNode *next;
    friend class LinkList;
};

class LinkList
{
    int len;
    ListNode *head;
public:
    int n, k, s;
    LinkList();
    ~LinkList();
    void CreateList();
    void Test();
};

LinkList::LinkList()
{
    head = new ListNode;
}

LinkList::~LinkList()
{
    delete head;
}

void LinkList::CreateList()
{
    len = n;
    ListNode *p = head;
    ListNode *q;
    for(int i=1; i<=n; i++)
    {
        q = new ListNode;
        q->data = i;
        p->next = q;
        p = p->next;
    }
    p->next = head;
}

void LinkList::Test()
{
    int i;
    ListNode *p = head;
    for(i=0; i<s-1; i++)
        p = p->next;
    while(len)
    {
        if(p->next==head)
            p = p->next;
        for(i=0; i<k-1; i++)
        {
            p = p->next;
            if(p->next==head)
                p = p->next;
        }
        ListNode *q = p->next;
        cout<<q->data;
        if (len!=1){
            cout<<" ";
        }
        p->next = q->next;
        delete q;
        len--;
    }
}

int main()
{
    int N, K, S;
    for (int i = 0; i < 2; ++i) {
        cin>>N>>K>>S;
        LinkList myList;
        myList.n = N;
        myList.k = K;
        myList.s = S;
        myList.CreateList();
        myList.Test();
        if (i!=1){
            cout<<endl;
        }
    }
    return 0;
}
