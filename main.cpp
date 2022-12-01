#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Node{
public:
    char data;
    Node* child[26];
    Node(){
        for (int i = 0; i < 26; ++i) {
            child[i]= nullptr;
        }
    }
    Node(char c){
        data=c;
        for (int i = 0; i < 26; ++i) {
            child[i]= nullptr;
        }
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string str){
        Node* temp=root;
        for (char ch : str) {
            if (temp->child[ch-'a']== nullptr){
                temp->child[ch-'a']=new Node(ch);
            }
            temp=temp->child[ch-'a'];
        }
    }
    void BFS(){
        if (!root){
            return;
        }
        queue<Node*> que;
        que.push(root);
        while (!que.empty()){
            auto temp=que.front();
            que.pop();
            cout<<temp->data;
            for (int i = 0; i < 26; ++i) {
                if (temp->child[i]){
                    que.push(temp->child[i]);
                }
            }
        }
        cout<<endl;
    }
    void getPre(string str){

    }

    void parse(string str){
        string str1;
        for (int i = 0; i < str.size(); ++i) {
            char ch=str.at(i);
            if (ch==' '){
                insert(str1);
                cout<<
                str1.clear();
            } else{
                str1.push_back(ch);
            }
        }
    }
    void main(string str){
        parse(str);

        BFS();

//        int n;
//        cin>>n;
//        while (n--){
//            string str;
//            cin>>str;
//            getPre(str);
//        }
    }
};



int main(){
    string str;
    while (1){
        getline(cin,str);
        if (!str.size()){
            break;
        }
        Trie trie;
        trie.main(str);
    }
}