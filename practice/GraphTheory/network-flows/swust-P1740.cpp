#include <bits/stdc++.h>
using namespace std;
const int maxn=500,inf=0x3f3f3f3f;
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
int a[maxn],b[maxn];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int s=0,t=n+m+1;
    init(n+m+10);
    int sum=0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            addedge(i,j+n,1);
    }

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
        addedge(s,i,a[i]);
    }

    for(int i=1; i<=m; i++)
    {
        scanf("%d",&b[i]);
        addedge(i+n,t,b[i]);
    }

    if(Maxflow(s,t)<sum)
        printf("0\n");
    else
    {
        printf("1\n");

        for(int i=0; i<n*m*2; i+=2)
        {
            if(es[i].flow>0)
                printf("%d ",es[i].to-n);

            if(es[i].to-n==m)
                printf("\n");
        }
    }

    return 0;
}
