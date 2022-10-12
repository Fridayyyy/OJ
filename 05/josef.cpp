#include<iostream>
using namespace std;

class Joseph
{
public:
    Joseph(int m_n,int m_m,int m_k)
    {
        n=m_n;
        m=m_m;
        k=m_k;
    }
    void simulate()
    {
        int a[1000]={0},i,j=0,t=0;
        for(i=k-1;t<n-1;i++)
        {
            if(a[i]!=1)
            {
                j++;
            }
            if(j==m)
            {
                cout<<i+1<<" ";
                a[i]=1;
                j=0;
                t++;
            }
            if((i+1)==n)
            {
                i=(-1);
            }
        }
        for(i=0;i<n;i++)
        {
            if(a[i]!=1) cout<<i+1<<endl;
        }

    }
private:
    int n;
    int m;
    int k;
};

int main()
{
    int m,n,k;
    for (int i = 0; i < 2; ++i) {
        cin>>n>>m>>k;
        Joseph obj(n, m,k);
        obj.simulate();
    }
    return 0;
}