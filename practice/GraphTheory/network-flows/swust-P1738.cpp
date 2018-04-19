#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,S,T,to[N],head[N],cur[N],dis[N];
struct node
{
    int v,next,cap,flow;
    node(int v=0,int next=0,int cap=0,int flow=0):v(v),next(next),cap(cap),flow(flow) {}
} e[N<<1];
int tot=1;
bool vis[N];
void add(int x,int y,int z)
{
    e[++tot]=node(y,head[x],z,0);
    head[x]=tot;
}
bool bfs()
{
    memset(dis,0,sizeof dis);
    queue<int>q;
    q.push(S);
    dis[S]=1;

    while(!q.empty())
    {
        int x=q.front();
        q.pop();

        for(int i=head[x]; i; i=e[i].next)
        {
            int v=e[i].v;

            if(!dis[v]&&e[i].cap>e[i].flow)
            {
                dis[v]=dis[x]+1;
                q.push(v);
            }
        }
    }

    return dis[T];
}
int dfs(int x,int f)
{
    if(x==T)
        return f;

    for(int i=head[x]; i; i=e[i].next)
    {
        int v=e[i].v,f1;

        if(dis[x]+1==dis[v]&&e[i].cap>e[i].flow)
        {
            if(f1=dfs(v,min(f,e[i].cap-e[i].flow)))
            {
                e[i].flow+=f1;
                e[i^1].flow-=f1;
                return f1;
            }
        }
    }

    return 0;
}
int dinic()
{
    int ans=0;

    while(bfs())
        ans+=dfs(S,0x7fffffff);

    return ans;
}
int main()
{
    //freopen("path3.in","r",stdin);
    //freopen("path3.out","w",stdout);
    scanf("%d%d",&n,&m);
    S=0;
    T=n<<1|1;

    for(int i=1,x,y; i<=m; i++)
        scanf("%d%d",&x,&y),add(x,y+n,1),add(y+n,x,0);

    for(int i=1; i<=n; i++)
        add(S,i,1),add(i,S,0),add(i+n,T,1),add(T,i+n,0);

    int ans=n-dinic();

    for(int i=1; i<=n; i++)
    {
        for(int j=head[i]; j; j=e[j].next)
        {
            if(e[j].flow==1)
            {
                to[i]=e[j].v-n;
                break;
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            while(i)
                vis[i]=1,printf("%d ",i),i=to[i];

            printf("\n");
        }
    }

    printf("%d\n",ans);
    return 0;
}