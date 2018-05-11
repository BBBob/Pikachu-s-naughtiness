#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
const int maxn=410,inf=0x3f3f3f3f;
struct edge
{
    int from,to,cap,flow;
};
vector<edge>es;
vector<int>G[maxn];
bool vis[maxn];
int dist[maxn];
int iter[maxn];
ll arr[maxn][maxn];
int cow[maxn],val[maxn];
int tot=0,n,m;
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
void floyd(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
    return ;
}
int check(ll t){
    init(2*n+1);
    int s=0;
    int tt=2*n+1;
    for(int i=1;i<=n;i++)
    {
        addedge(s,i,cow[i]);addedge(i+n,tt,val[i]);addedge(i,i+n,inf);
        for(int j=i+1;j<=n;j++){
            if(arr[i][j]<=t){
                addedge(i,j+n,inf);
                addedge(j,i+n,inf);
            }
        }
    }
    if(Maxflow(s,tt)>=tot) return 1;
    else return 0;
}
void solve(){
    floyd();
    ll l=0,r=1e15-1;
    ll ans=-1;
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
        //printf("%lld\n",ans);
    }
    printf("%lld\n",ans);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d%d",&cow[i],&val[i]),tot+=cow[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) arr[i][j]=1e15;
    for(int i=1;i<=m;i++){
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        if(arr[u][v]>w) arr[u][v]=arr[v][u]=w;
    }
    solve();
    return 0;
}
