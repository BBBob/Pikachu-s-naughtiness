#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
const int M = 1e5+7;
const int N = 2e5+7;
const int maxb = 22;
vector<int> vec[M];
struct lian
{
    int u,v,w;
    lian(int u1,int v1,int w1) {
        u=u1;
        v=v1;
        w=w1;
    }
};
vector<lian> vec1[M];
int in[M],out[M],lca[M][maxb],deep[N],dp[M],c[N],sum[M],tot,n,m;
void init()
{
    for(int i=1; i<=n; i++)
    {
        vec[i].clear();
        vec1[i].clear();
    }

    memset(dp,0,sizeof(dp));
    memset(lca,0,sizeof(lca));
    memset(c,0,sizeof(c));
    memset(sum,0,sizeof(sum));
    tot=0;
}
void dfs(int u,int fa,int dep)
{
    deep[u]=dep;
    in[u]=++tot;
    lca[u][0]=fa;

    for(int i=1; i<maxb; i++)
    {
        int tmp=lca[u][i-1];
        lca[u][i]=lca[tmp][i-1];
    }

    for(int i=0; i<vec[u].size(); i++)
    {
        int v=vec[u][i];

        if(v==fa)
            continue;

        dfs(v,u,dep+1);
    }

    out[u]=++tot;
}
int LCA(int u,int v)
{
    if(deep[u]<deep[v])
        swap(u,v);

    for(int i=maxb-1; i>=0; i--)
    {
        if(deep[lca[u][i]]>=deep[v])
            u=lca[u][i];
    }

    if(u==v)
        return v;

    for(int i=maxb-1; i>=0; i--)
    {
        if(lca[u][i]!=lca[v][i])
        {
            u=lca[u][i];
            v=lca[v][i];
        }
    }

    return lca[u][0];
}
int lowbit(int x)
{
    return x&(-x);
}
void update(int x,int y)
{
    for(int i=x; i<N; i+=lowbit(i))
        c[i]+=y;
}
int getsum(int x)
{
    int ans=0;

    for(int i=x; i>0; i-=lowbit(i))
        ans+=c[i];

    return ans;
}
void getval(int u,int fa)
{
    for(int i=0; i<vec[u].size(); i++)
    {
        int v=vec[u][i];

        if(v==fa)
            continue;

        getval(v,u);
        sum[u]+=dp[v];
    }

    dp[u]=sum[u];

    for(int i=0; i<vec1[u].size(); i++)
    {
        int from=vec1[u][i].u,to=vec1[u][i].v,w=vec1[u][i].w;
        dp[u]=max(dp[u],sum[u]+w+getsum(in[from])+getsum(in[to]));
    }

    update(in[u],sum[u]-dp[u]);
    update(out[u],dp[u]-sum[u]);
}
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();

        for(int i=1; i<n; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        dfs(1,-1,1);

        //for(int i=1;i<=n;i++) printf("%d %d\n",in[i],out[i]);
        for(int i=1; i<=m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            vec1[LCA(u,v)].push_back(lian(u,v,w));
            //printf("%d\n",LCA(u,v));
        }

        getval(1,-1);
        //for(int i=1;i<=n;i++) printf("%d %d\n",sum[i],dp[i]);
        printf("%d\n",dp[1]);
    }

    return 0;
}
