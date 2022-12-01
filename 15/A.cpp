#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(){
        next=nullptr;
        data=-1;
    }
    Node(int d){
        data=d;
        next=nullptr;
    }
//    void insert(int d){
//        Node* node=new Node(d);
//        while (){
//
//        }
//
//    }
    int search(int d){
        int count=0;
        Node* temp= this;
        while (temp){
            count++;
            if (temp->data==d){
                return count-1;
            }
            temp=temp->next;
        }
        return -1;
    }

};
class HashTable{
    Node** root;
    int size;
public:
    HashTable(){
        cin>>size;
        root=new Node*[11];
        for (int i = 0; i < 11; ++i) {
            root[i]=new Node();
        }
    }
    int Hash(int n){
        return n % 11;
    }
    void insert(int n){
        int hash= Hash(n);
        Node* node=new Node(n);
        Node* temp=root[hash];
        while (temp->next){
            temp=temp->next;
        }
        temp->next=node;
    }
    void search(int n){
        int hash= Hash(n);
        int count=root[hash]->search(n);
        if (count>-1){
            cout<<hash<<" "<<count<<endl;
        }else{
            cout<<"error"<<endl;
            insert(n);
        }
    }
    void main(){
        for (int i = 0; i < size; ++i) {
            int n;
            cin>>n;
            insert(n);
        }

        int n;
        cin>>n;
        while (n--){
            int num;
            cin>>num;
            search(num);
        }
    }

};


int main(){
    HashTable hashTable;
    hashTable.main();
}
