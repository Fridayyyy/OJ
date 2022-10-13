//
// Created by 86184 on 2022/10/12.
//
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class Node{
public:
    char val;
    Node *left;
    Node *right;
    int weight;

    Node(){
        left= nullptr;
        right= nullptr;
        weight=0;
    }
    explicit Node(char c){
        val=c;
        left= nullptr;
        right= nullptr;
    }
};

class Tree{
    Node *root;
    int pos;
    string strTree;

    int maxWeight;
    queue<int> weights;

    Node* createTree();
    void getWeight(Node* node,int road);
public:
    Tree();
    ~Tree();
    void createTree(string str);
    void getWeight();
    void setWeights(queue<int> q);
};
Tree::Tree() {
    root= nullptr;
    pos=0;
    maxWeight=0;
}

void Tree::createTree(std::string str) {
    strTree.assign(str);
    pos=0;
    root=createTree();
}

Node *Tree::createTree() {
    Node* T;
    char ch;
    ch=strTree[pos++];
    if (ch=='0'){
        T= nullptr;
    } else{
        T=new Node(ch);
        T->left=createTree();
        T->right=createTree();
    }
    return T;
}

void Tree::getWeight() {
    getWeight(root,0);
    cout<<maxWeight<<endl;
}

void Tree::getWeight(Node *node, int road) {
    if (node){
        node->weight=weights.front()+road;
        weights.pop();
        getWeight(node->left,node->weight);
        getWeight(node->right,node->weight);
        if (!node->left&&!node->right){
            maxWeight= max(maxWeight,node->weight);
        }
    }
}

void Tree::setWeights(queue<int> q) {
    weights=q;
}

Tree::~Tree() {

}

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        //输入的字符串
        string str1;
        cin>>str1;

        //将每个权重放入queue
        int count;
        cin>>count;
        queue<int> que;
        while (count--){
            int num;
            cin>>num;
            que.push(num);
        }

        Tree t;
        t.createTree(str1);
        t.setWeights(que);
        t.getWeight();
    }
}
