#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long LL;
const int M = 1e6+7;
vector<pair<int,int> > vec[M];
int n,vis[M],uu,vv,num=2,edge;
LL dp[M][2],val[M];
void getval(int u,int fa)
{
    dp[u][1]=val[u],dp[u][0]=0;

    for(int i=0; i<vec[u].size(); i++)
    {
        int v=vec[u][i].f,nn=vec[u][i].s;

        if(v==fa)
            continue;

        if(nn==edge||nn==(edge^1))
            continue;

        getval(v,u);
        dp[u][0]+=max(dp[v][0],dp[v][1]);
        dp[u][1]+=dp[v][0];
    }
}
void dfs(int u,int fa)
{
    vis[u]=1;

    for(int i=0; i<vec[u].size(); i++)
    {
        int v=vec[u][i].f,nn=vec[u][i].s;

        if(v==fa)
            continue;

        if(vis[v])
            uu=u,vv=v,edge=nn;
        else
            dfs(v,u);
    }
}
int main()
{
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        int v;
        scanf("%lld%d",&val[i],&v);
        vec[i].push_back(make_pair(v,num++));
        vec[v].push_back(make_pair(i,num++));
    }

    memset(vis,0,sizeof(vis));
    LL ans=0;

    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            dfs(i,-1);
            getval(uu,-1);
            LL tmp=dp[uu][0];
            getval(vv,-1);
            tmp=max(tmp,dp[vv][0]);
            ans+=tmp;
        }
    }

    printf("%lld\n",ans);
    return 0;
}
