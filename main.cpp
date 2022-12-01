#include <iostream>
#include <queue>

using namespace std;

class Node{
public:
    int count;
    string data;
    Node* child;
    Node(){
        count=0;

    }
};

class Trie{
    Node* root;
public:
    Trie(){

    }
    void insert(){

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
            for (int i = 0; i < 26; ++i) {
                if ()
            }
        }
    }
    void getPre(string str){

    }
    void main(){


        BFS();

        int n;
        cin>>n;
        while (n--){
            string str;
            cin>>str;
            getPre(str);
        }
    }
};


int main(){

}