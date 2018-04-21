#include <bits/stdc++.h>
using namespace std;
const int M = 1e5+7;
typedef long long LL;
struct tree
{
    int next[26];
    int sz=0,z=0;
    LL sum=0,lazy=0,val=0;
} T[M];
string name;
int id,tot=1;
LL ans;
void update(int rt)
{
    T[rt].sum += T[rt].lazy*T[rt].sz;
    T[rt].val += T[rt].lazy*T[rt].z;

    if(T[rt].lazy != 0)
    {
        for(int i = 0; i < 26; i++)
            T[T[rt].next[i]].lazy += T[rt].lazy;
    }

    T[rt].lazy = 0;
}
void ins(string x,LL y)
{
    int pos=1;

    for(int i=0; i<x.size(); i++)
    {
        int tmp=x[i]-'a';

        if(T[pos].next[tmp]==0)
        {
            T[pos].next[tmp]=tot+1;
            tot++;
            pos=tot;
        }
        else
            pos=T[pos].next[tmp];

        if(T[pos].lazy != 0)
            update(pos);

        T[pos].sum+=y;
        T[pos].sz++;
    }

    T[pos].z++;
    T[pos].val+=y;
}
void updatee(string x,LL y)
{
    int pos=1;

    for(int i=0; i<x.size(); i++)
    {
        int tmp=x[i]-'a';
        pos=T[pos].next[tmp];

        if(pos==0)
            return ;
    }

    //T[pos].sum+=(T[pos].sz*y);
    T[pos].lazy+=y;
    LL kk=T[pos].sz*y;
    int pos1=1;

    for(int i=0; i<x.size()-1; i++)
    {
        int tmp=x[i]-'a';
        pos1=T[pos1].next[tmp];
        T[pos1].sum+=kk;
    }
}
void q(string x)
{
    int pos=1;
    ans=0;

    for(int i=0; i<x.size(); i++)
    {
        int tmp=x[i]-'a';

        if(T[pos].next[tmp]!=0)
            pos=T[pos].next[tmp];
        else
        {
            ans=0;
            return ;
        }

        if(T[pos].lazy != 0)
            update(pos);
    }

    if(id==3)
    {
        ans=T[pos].val;
        return ;
    }

    ans=T[pos].sum;
    return ;
}
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        LL x;
        name.clear();
        scanf("%d",&id);

        if(id==1)
        {
            cin>>name>>x;
            ins(name,x);
        }
        else if(id==2)
        {
            cin>>name>>x;
            updatee(name,x);
        }
        else
        {
            cin>>name;
            q(name);
            printf("%lld\n",ans);
        }
    }

    return 0;
}
