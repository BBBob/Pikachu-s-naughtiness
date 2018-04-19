#include <bits/stdc++.h>
using namespace std;
const int maxn=20500,inf=0x3f3f3f3f;
struct edge
{
    int from,to,cap,flow;
};
vector<edge>es;
vector<int>G[maxn];
bool vis[maxn];
int dist[maxn];
int iter[maxn];
int read()
{
    char c=getchar();
    int x=0,f=1;

    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;

        c=getchar();
    }

    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }

    return x*f;
}
int n,a[maxn],f[maxn],g[maxn],s,t,l;
void dp()
{
    for(int i=1; i<=n; i++)
        g[i]=inf;

    for(int i=1; i<=n; i++)
    {
        int k=upper_bound(g+1,g+1+n,a[i])-g;
        f[i]=k;
        g[k]=a[i];
        l=max(l,f[i]);
    }
}
void init(int x)
{
    for(int i=0; i<=x+10; i++)
        G[i].clear();

    es.clear();
}
void addedge(int from,int to,int cap)
{
    es.push_back((edge)
    {
        from,to,cap,0
    });
    es.push_back((edge)
    {
        to,from,0,0
    });
    int x=es.size();
    G[from].push_back(x-2);
    G[to].push_back(x-1);
}
bool BFS(int s,int t)
{
    memset(vis,0,sizeof(vis));
    queue <int> Q;
    vis[s]=1;
    dist[s]=0;
    Q.push(s);

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();

        for(int i=0; i<G[u].size(); i++)
        {
            edge &e=es[G[u][i]];

            if(!vis[e.to]&&e.cap>e.flow)
            {
                vis[e.to]=1;
                dist[e.to]=dist[u]+1;
                Q.push(e.to);
            }
        }
    }

    return vis[t];
}
int DFS(int u,int t,int f)
{
    if(u==t||f==0)
        return f;

    int flow=0,d;

    for(int &i=iter[u]; i<G[u].size(); i++)
    {
        edge &e=es[G[u][i]];

        if(dist[u]+1==dist[e.to]&&(d=DFS(e.to,t,min(f,e.cap-e.flow)))>0)
        {
            e.flow+=d;
            es[G[u][i]^1].flow-=d;
            flow+=d;
            f-=d;

            if(f==0)
                break;
        }
    }

    return flow;
}
int Maxflow(int s,int t)
{
    int flow=0;

    while(BFS(s,t))
    {
        memset(iter,0,sizeof(iter));
        int d=0;

        while(d=DFS(s,t,inf))
            flow+=d;
    }

    return flow;
}
void build()
{
    for(int i=1; i<=n; i++)
    {
        if(f[i]==1)
            addedge(s,i,1);

        addedge(i,i+n,1);

        if(f[i]==l)
            addedge(i+n,t,1);

        for(int j=1; j<i; j++)
            if(a[j]<=a[i]&&f[j]+1==f[i])
                addedge(j+n,i,1);
    }
}
void build2()
{
    for(int i=1; i<=n; i++)
    {
        if(i==1||i==n)
        {
            if(f[i]==1)
                addedge(s,i,inf);

            addedge(i,i+n,inf);

            if(f[i]==l)
                addedge(i+n,t,inf);
        }
        else
        {
            if(f[i]==1)
                addedge(s,i,1);

            addedge(i,i+n,1);

            if(f[i]==l)
                addedge(i+n,t,1);
        }

        for(int j=1; j<i; j++)
            if(a[j]<=a[i]&&f[j]+1==f[i])
                addedge(j+n,i,1);
    }
}
int main()
{
    n=read();
    s=1;
    t=n+n+1;

    for(int i=1; i<=n; i++)
        a[i]=read();

    dp();
    printf("%d\n",l);

    if(l==1)
    {
        printf("%d\n%d",n,n);
        return 0;
    }

    build();
    printf("%d\n",Maxflow(s,t));
    init(t+1);
    build2();
    printf("%d",Maxflow(s,t));
    return 0;
}
