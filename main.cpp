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
        data=0;
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
            Node* temp=que.front();
            que.pop();
            //cout<<temp->data;
            for (int i = 0; i < 26; ++i) {
                if (temp->child[i]){
                    cout<<temp->child[i]->data;
                    que.push(temp->child[i]);
                }
            }
        }
        cout<<endl;
    }
    int getPre(string str){
        int sum=0;
        Node* temp=root;
        for (int i = 0; i < str.size(); ++i) {
            char c=str[i];
            if (temp->child[c-'a']== nullptr){
                return 0;
            }
            temp=temp->child[c-'a'];
        }
        helper(temp,sum);
        return sum;
    }

    void helper(Node *node,int &sum){
        Node* temp=node;
        bool isEnd= false;
        for (auto & i : temp->child) {
            if (i){
                helper(i,sum);
                isEnd= true;
            }
        }
        if (!isEnd){
            sum++;
            return;
        }
    }

    void parse(string str){
        string str1;
        for (char ch : str) {
            if (ch==' '){
                insert(str1);
                //cout<<str1<<" ";
                str1.clear();
            } else{
                str1.push_back(ch);
            }
        }
        //cout<<str1<<endl;
        insert(str1);
    }
    void main(string str){
        parse(str);
        BFS();

        int n;
        cin>>n;
        while (n--){
            string str1;
            cin>>str1;
            cout<<getPre(str1)<<endl;
        }
    }
};



int main(){
    char ch;
    string str;
    while ((ch=getchar())!=EOF){
        //string str;
        //getline(cin,str);
        //cout<<str.size()<<endl;
//        if (str.size()==0){
//            break;
//        }
        if (ch=='\n'){
            Trie trie;
            trie.main(str);
            //getchar();
        } else{
            str.push_back(ch);
        }

    }
}