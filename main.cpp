#include <iostream>
#include <queue>

using namespace std;

class Node{
public:
    char data;
    Node *left;
    Node *right;
    int road;

    Node():left(nullptr),right(nullptr){}
    Node(char c):data(c),left(nullptr),right(nullptr){}
    ~Node(){delete left;delete right;}
};
class Tree{
    Node *root;
    int count;
    queue<int> weight
};