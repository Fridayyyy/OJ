#include <iostream>
#include <queue>

using namespace std;


const int MAX=20;

class ArcNode{
public:
    int adjvex;//该弧指向的顶点位置
    ArcNode *nextarc;
    ArcNode(int adj,ArcNode* next){
        adjvex=adj;
        nextarc=next;
    }
};
class VNode{
public:
    char data;
    ArcNode *firstArc;
    VNode(){
        data=NULL;
        firstArc= nullptr;
    }
};
class ALGraph{
    int vNum,arcNum;
    VNode vNodes[MAX];
public:
    void display();
    void create();
    int locate(char ch);
    ALGraph(){
        for (int i = 0; i < MAX; ++i) {
            vNodes[i].firstArc= nullptr;
        }
    }
};

int ALGraph::locate(char ch) {
    int i;
    for (i=0; i < vNum; ++i) {
        if (vNodes[i].data==ch)
            break;
    }
    return i;
}

void ALGraph::display() {
    for (int i = 0; i < vNum; ++i) {
        cout<<i<<" ";
        ArcNode *node=vNodes[i].firstArc;
        cout<<vNodes[i].data<<"-";
        while (node){
            cout<<node->adjvex<<"-";
            node=node->nextarc;
        }
        cout<<"^"<<endl;
    }
}

void ALGraph::create() {
    cin>>vNum>>arcNum;
    char ch;
    for (int i = 0; i < vNum; ++i) {
        cin>>ch;
        vNodes[i].data=ch;
    }
    char c1,c2;
    for (int i = 0; i < arcNum; ++i) {
        cin>>c1>>c2;
        int index1= locate(c1);
        int index2= locate(c2);

        ArcNode *node=new ArcNode(index2, nullptr);
        if (!vNodes[index1].firstArc){
            vNodes[index1].firstArc=node;
        } else{
            auto temp=vNodes[index1].firstArc;
            while (temp->nextarc){
                temp=temp->nextarc;
            }
            temp->nextarc=node;
        }
    }
}


int main(){
    int t;
    cin>>t;
    while (t--){
        ALGraph graph;
        graph.create();
        graph.display();
    }
}