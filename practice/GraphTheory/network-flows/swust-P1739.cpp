#include <bits/stdc++.h>
using namespace std;
const int maxn=20500,inf=0x3f3f3f3f;
const int m=5000;
const int T=10000;
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
int ans=0,s=0,n;
int main()
{
    cin>>n;

    for(;;)
    {
        ans++,s++;

        for(int i=1; i<s; i++)
            if(sqrt(i+s)==(int)sqrt(i+s))
                addedge(i,s+m,1);

        addedge(0,s,1),addedge(s+m,T,1);
        ans-=Maxflow(0,T);

        if(ans>n)
            break;
    }

    int i,j;
    init(T+1);

    for(i=1; i<s; i++)
    {
        addedge(0,i,1);
        addedge(i+m,T,1);

        for(j=1; j<i; j++)
            if(sqrt(i+j)==(int)sqrt(i+j))
                addedge(j,i+m,1);
    }

    Maxflow(0,T);
    printf("%d\n",s-1);
    int match[maxn],vv[maxn],path[maxn];
    memset(match,0,sizeof(match));
    memset(vv,0,sizeof(vv));

    for(int i=1; i<s; i++)
    {
        for(int j=0; j<G[i].size(); j++)
        {
            if(es[G[i][j]].flow==1)
            {
                //printf("%d ",es[G[i][j]].to-m);
                match[i]=es[G[i][j]].to-m;
            }
        }

        //printf("\n");
    }

    for(i=1; i<s; i++)
    {
        if(vv[i])
            continue;

        int p=0;

        for(j=i; j; j=match[j])
        {
            path[++p]=j;
            vv[j]=1;
        }

        for(j=1; j<p; j++)
            printf("%d ",path[j]);

        printf("%d\n",path[j]);
    }

    return 0;
}
