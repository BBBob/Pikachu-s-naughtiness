//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=6e5+7;

struct state
{
    int link,len;
    map<int,int> next;
} st[Nmax<<1];
int size,last,root;
inline int newnode(int _len)
{
    ++size;
    st[size].len=_len;
    st[size].link=0;
    st[size].next.clear();
    return size;
}
inline void Extend(int c)
{
    int cur=newnode(st[last].len+1),p;

    for(p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
        st[p].next[c]=cur;

    if(p==-1)
        st[cur].link=root;
    else
    {
        int q=st[p].next[c];

        if(st[q].len==st[p].len+1)
            st[cur].link=q;
        else
        {
            int nq=newnode(st[p].len+1);//注意是p，不是q
            //st[nq].len=st[p].len+1;
            st[nq].next=st[q].next;
            st[nq].link=st[q].link;

            for(; p!=-1 && st[p].next[c]==q; p=st[p].link)
                st[p].next[c]=nq;

            st[cur].link=st[q].link=nq;
        }
    }

    last=cur;
}
inline void init()
{
    size=0,last=0;
    st[0].link=-1;
}

int a[Nmax];


int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);

    init();

    for(int i=1; i<=n; i++)
        Extend(a[i]);

    for(int i=1; i<=n; i++)
        Extend(a[i]);

    int now=0;

    for(int i=1; i<=n; i++)
    {
        printf("%d%c",st[now].next.begin()->first,i==n?'\n':' ');
        now=st[now].next.begin()->second;
    }

    return 0;
}


