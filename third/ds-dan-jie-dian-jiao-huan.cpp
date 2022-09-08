//
// Created by ����� on 2022/9/8.
//
#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *next;
    Node(int val):value(val),next(nullptr){}
};
void display(Node* node){
    while (node){
        cout<<node->value<<" ";
        node=node->next;
    }
    cout<<endl;
}
void swapNode(Node* node,int a,int b){
    if (a>b){
        swap(a,b);
    }

    Node* head1=node;
    Node* head2=node;
    for (int i = 0; i < a-1; ++i) {
        head1=head1->next;
    }
    for (int i = 0; i < b-1; ++i) {
        head2=head2->next;
    }


    //temp1��Ҫ�����ĵ�һ���ڵ㣬temp2��Ҫ�����ĵڶ����ڵ�
    Node* temp1=head1->next;
    Node* temp2=head2->next;

    Node* pNode=temp1->next;
    //head1:��һ��Ŀ��ڵ��ǰһ����head2���ڶ���Ŀ��ڵ��ǰһ��
    head2->next=temp1;
    temp1->next=temp2->next;

    head1->next=temp2;
    temp2->next=pNode;

}
int main(){
    int n;
    Node* head=new Node(-1);
    Node* temp=head;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int val;
        cin>>val;
        temp->next=new Node(val);
        temp=temp->next;
    }
    display(head->next);

    int a,b,c,d;
    cin>>a>>b;
    if (a>n||b>n){
        cout<<"error"<<endl;
    } else{
        Node* node= head;
        swapNode(node,a,b);
        display(head->next);
    }


    cin>>c>>d;
    if(c>n||d>n){
        cout<<"error"<<endl;
    }
    else{
        swapNode(head->next,c,d);
        display(head->next);
    }

    return 0;
}