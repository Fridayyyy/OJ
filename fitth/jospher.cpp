//
// Created by 86184 on 2022/9/16.
//
#include <iostream>

using namespace std;
class Node{
public:
    int index;
    Node* next{};

    explicit Node(int i){
        index=i;
    }
};
void creatRing(Node* head,int size){
    Node* pointer=head;
    for (int i = 1; i < size; ++i) {
        Node* next=new Node(i+1);
        pointer->next=next;
        pointer=pointer->next;
    }
    pointer->next=head;
}

void helper(Node* head,int killSize,int s){
    Node* first=head;
    Node* temp;
    if (s!=1){
        while (first->index!=killSize){
            temp=first;
            first=first->next;
        }
    }

    while (first->next&&first->next!=first){
        if (s==1){
            for (int i = 1; i < killSize; ++i) {
                temp=first;
                first=first->next;
            }
        }

        for (int i = 1; i < s; ++i) {
            temp= first;
            first=first->next;
        }
        cout<<first->index<<" ";
        temp->next=first->next;
        delete first;
        first=temp->next;
    }
    cout<<first->index<<endl;
}
int main(){

    int N,K,S;
    while (cin>>N>>K>>S){
        Node* head=new Node(1);
        creatRing(head,N);
        helper(head,K,S);
    }

}