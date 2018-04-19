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
int s=0,t=9999,flow=0;
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
    while(BFS(s,t))
    {
        memset(iter,0,sizeof(iter));
        int d=0;

        while(d=DFS(s,t,inf))
            flow+=d;
    }

    return flow;
}
int xh[101][101];
int len[101];
int ma[101];
int main()
{
    init(t+1);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    n+=2;

    for(int i=1; i<=m; i++)
    {
        scanf("%d",&ma[i]);
        scanf("%d",&len[i]);

        for(int j=0; j<len[i]; j++)
        {
            scanf("%d",&xh[i][j]);
            xh[i][j]+=2;
        }
    }

    int ans=0;

    while(1)
    {
        if(ans==100)
            break;

        addedge(ans*n+1,t,inf);
        addedge(s,ans*n+2,inf);

        if(ans!=0)
        {
            for(int i=1; i<=n; i++)
                addedge((ans-1)*n+i,ans*n+i,inf);

            for(int i=1; i<=m; i++)
            {
                int x=xh[i][(ans-1)%len[i]];
                int y=xh[i][ans%len[i]];
                addedge((ans-1)*n+x,ans*n+y,ma[i]);
            }
        }

        if(Maxflow(s,t)>=k)
            break;

        ans++;
    }

    if(ans==100)
        cout<<0;
    else
        cout<<ans;

    return 0;
}
