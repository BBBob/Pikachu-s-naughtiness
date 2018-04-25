#include <bits/stdc++.h>
using namespace std;
const int maxn=500,inf=0x3f3f3f3f;
typedef long long LL;
struct edge
{
    int from,to,cap,flow;
};
vector<edge>es;
vector<int>G[maxn];
bool vis[maxn];
int dist[maxn];
int iter[maxn];
void init(int n)
{
    for(int i=0; i<=n+10; i++)
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
LL Maxflow(int s,int t)
{
    LL flow=0;

    while(BFS(s,t))
    {
        memset(iter,0,sizeof(iter));
        int d=0;

        while(d=DFS(s,t,inf))
            flow+=d;
    }

    return flow;
}
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        LL ans=0;
        init(n+m+1);
        int s=0,t=n+m+1;

        for(int i=1; i<=n; i++)
        {
            int x;
            scanf("%d",&x);
            addedge(0,i,x);
            ans+=x;
        }

        for(int i=1; i<=m; i++)
        {
            int x;
            scanf("%d",&x);
            addedge(i+n,t,x);
        }

        for(int i=1; i<=n; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);

            for(int j=0; j<x; j++)
            {
                int xx;
                scanf("%d",&xx);
                addedge(i,n+xx,inf);
            }

            for(int j=0; j<y; j++)
            {
                int xx;
                scanf("%d",&xx);
                addedge(i,xx,inf);
            }
        }

        printf("%lld\n",ans-Maxflow(s,t));
    }

    return 0;
}
