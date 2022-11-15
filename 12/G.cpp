#include<iostream>
using namespace std;
const int Inf = 999999;
const int MaxVex = 100;
class Map
{
private:
    int matrix[MaxVex][MaxVex];
    string vexname[MaxVex];
    int vexnum;
    string startVex;
public:
    Map();
    ~Map(){}
    int find(string s);
    int getMinDis();//通过Prim算法计算出最小生成树的权值
    void Prim();
    void Kruskal();
};
Map::Map()
{
    int i,j,lnum;
    cin >> vexnum;
    for(i = 0;i < vexnum;i++)
    {
        cin >> vexname[i];
        for(j = 0;j < vexnum;j++)
        {
            matrix[i][j] = Inf;
        }
    }
    cin >> lnum;
    int value,index1,index2;
    string s1,s2;
    for(i = 0;i < lnum;i++)
    {
        cin >> s1 >> s2 >> value;
        index1 = find(s1);
        index2 = find(s2);
        matrix[index1][index2] = value;
        matrix[index2][index1] = value;
    }
    cin >> startVex;
}
int Map::find(string s)
{
    for(int i = 0;i < vexnum;i++)
    {
        if(vexname[i] == s)
        {
            return i;
        }
    }
    cout << "find_error" << endl;
    return -1;
}
int Map::getMinDis()
{
    int sum = 0,i,j;
    int dis[MaxVex];
    bool visit[MaxVex];
    for(i = 0;i < vexnum;i++)
    {
        dis[i] = Inf;
        visit[i] = false;
    }
    int start = find(startVex);
    dis[start] = 0;
    for(i = 0;i < vexnum;i++)
    {
        int min = Inf;
        int index = -1;
        //选出最小的节点
        for(j = 0;j < vexnum;j++)
        {
            if(dis[j] < min && !visit[j])
            {
                min = dis[j];
                index = j;
            }
        }
        if(index >= 0)
        {
            visit[index] = true;
            sum += min;
            //更新dis
            for(j = 0;j < vexnum;j++)
            {
                if(matrix[index][j] < dis[j])
                {
                    dis[j] = matrix[index][j];
                }
            }
        }
    }
    return sum;
}
void Map::Prim()
{
    cout << "prim:" << endl;
    int i,j;
    int dis[MaxVex];
    bool visit[MaxVex];
    int from[MaxVex];
    for(i = 0;i < vexnum;i++)
    {
        dis[i] = Inf;
        visit[i] = false;
        from[i] = -1;
    }
    int start = find(startVex);
    dis[start] = 0;
    for(i = 0;i < vexnum;i++)
    {
        int min = Inf;
        int index = -1;
        //选出最小的节点
        for(j = 0;j < vexnum;j++)
        {
            if(dis[j] < min && !visit[j])
            {
                min = dis[j];
                index = j;
            }
        }
        if(index >= 0)
        {
            visit[index] = true;
            if(i != 0)
            {
                cout << vexname[from[index]] << " " << vexname[index] << " " << dis[index] << endl;
            }
            //更新dis
            for(j = 0;j < vexnum;j++)
            {
                if(matrix[index][j] < dis[j])
                {
                    dis[j] = matrix[index][j];
                    from[j] = index;
                }
            }
        }
    }
}
void Map::Kruskal()
{
    cout << "kruskal:" << endl;
    int i,j;
    int belong[MaxVex];
    for(i = 0;i < vexnum;i++)
    {
        belong[i] = i;
    }
    int t = vexnum-1;
    while(t--)
    {
        int index1 = -1,index2 = -1,min = Inf;
        for(i = 0;i < vexnum;i++)
        {
            for(j = 0;j < vexnum;j++)
            {
                if(matrix[i][j] < min && belong[i] != belong[j])
                {
                    index1 = i;
                    index2 = j;
                    min = matrix[i][j];
                }
            }
        }
        if(belong[index1] < belong[index2])
        {
            int value = belong[index2];
            for(i = 0;i < vexnum;i++)
            {
                if(belong[i] == value)
                {
                    belong[i] = belong[index1];
                }
            }
        }
        else
        {
            int value = belong[index1];
            for(i = 0;i < vexnum;i++)
            {
                if(belong[i] == value)
                {
                    belong[i] = belong[index2];
                }
            }
        }
        cout << vexname[index1] << " " << vexname[index2] << " " << min << endl;
    }

}
int main()
{
    Map map;
    cout << map.getMinDis() << endl;
    map.Prim();
    map.Kruskal();
    return 0;
}