#include<iostream>
#include<string>
using namespace std;
int *getnext(string p)
{
    int j=0,k=-1;
    int *next=new int[p.size()];
    next[0]=-1;
    while(j<(int)p.size()-1)
    {
        if(k==-1||p[j]==p[k])
        {
            j++;
            k++;
            next[j]=k;
        }
        else
            k=next[k];
    }
    return next;
}

int KMP(string s,string p)
{
    int i=0,j=0;
    int *next=getnext(p);
    while(i<(int)s.size()&&j<(int)p.size())
    {
        if(j==-1||s[i]==p[j])
        {
            i++;
            j++;
        }
        else
            j=next[j];
    }
    if(j==(int)p.size())
        return i-j+1;
    return -1;
}
int Find(string s)
{
    int L=s.size();
    int Max=-1;
    for(int i=0;i<L;i++)
    {
        for(int j=i;j<L;j++)
        {
            string p=s.substr(i,j-1);
            string save=s;
            //找到第一个相等的位置
            int firstindex=KMP(s,p);
            //s的大小
            int slength=s.size();
            //p的大小
            int plength=p.size();
            //截取相等位置之前的字符串
            string S=s.substr(0,firstindex-1);
            //剩余部分的字符串
            string after=s.substr(firstindex-1+plength,slength);
            S+=after;
            if(KMP(S,p)!=-1)
            {
                int t=plength;
                if(t>Max)
                    Max=t;
            }
            s=save;
        }
    }
    if(Max==0)
        return -1;
    return Max;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        cout<<Find(s)<<endl;
    }
    return 0;
}