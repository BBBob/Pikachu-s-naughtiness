#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int M = 1e5+7;
typedef long long LL;
vector<pair<int,int> >vec[M];
int dis[M],a[M],b[M],fa[M],dfn[M],n,pos,cnt,vis[M];//a存环上的点 b存环上i到i+1点的距离
LL u[M],u1[M],v[M],v1[M],ans,f[M];//f表示该点的最大深度 ans表示环外树上的最大直径
void dfs(int u,int ff) //dfn为访问时间戳 vis判断该点是否在环上 fa表示该点的父亲节点 dis为该节点到父节点的距离
{
    dfn[u]=++pos;
    vis[u]=0;

    for(int i=0; i<vec[u].size(); i++)
    {
        int v=vec[u][i].f,w=vec[u][i].s;

        if(v==ff)
            continue;

        if(!dfn[v])
        {
            fa[v]=u;
            dis[v]=w;
            dfs(v,u);
        }
        else if(dfn[v]>dfn[u])
        {
            while(v!=u)
            {
                vis[v]=1;
                a[++cnt]=v,b[cnt]=dis[v];
                v=fa[v];
            }

            vis[v]=1;
            a[++cnt]=v,b[cnt]=w;
        }
    }
}
void dp(int u,int ff)
{
    for(int i=0; i<vec[u].size(); i++)
    {
        int v=vec[u][i].f,w=vec[u][i].s;

        if(v!=ff&&!vis[v])
        {
            //printf("1111%d\n",v);
            dp(v,u);
            ans=max(ans,f[v]+f[u]+w);
            f[u]=max(f[v]+w,f[u]);
        }
    }
}
int main()
{
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        vec[u].push_back(make_pair(v,w));
        vec[v].push_back(make_pair(u,w));
    }

    ans=cnt=pos=0;
    dfs(1,-1);//find circle

    //for(int i=1;i<=cnt;i++) printf("%d %d\n",a[i],b[i]);
    for(int i=1; i<=cnt; i++)
        dp(a[i],-1);//找每个点深度与最大子树直径

    LL sum=0,mx=0;//sum为1到i点距离 mx为1到i点中某点深度减去1到该点距离的最大值

    //for(int i=1;i<=cnt;i++) printf("%d %lld\n",a[i],f[a[i]]);
    for(int i=1; i<=cnt; i++) //u[i]表示1到i点中树深加1到j距离最大的  v[i]表示1到i点中两点深度与距离相加最大值
    {
        sum+=b[i-1];
        u[i]=max(u[i-1],f[a[i]]+sum);
        v[i]=max(v[i-1],mx+sum+f[a[i]]);
        mx=max(mx,f[a[i]]-sum);
    }

    LL tmp=b[cnt];
    b[cnt]=mx=sum=0;

    for(int i=cnt; i>=1; i--) //从后向前遍历 意义同上
    {
        sum+=b[i];
        u1[i]=max(u1[i+1],f[a[i]]+sum);
        v1[i]=max(v1[i+1],f[a[i]]+sum+mx);
        mx=max(mx,f[a[i]]-sum);
    }

    LL mn=v[cnt];//v[cnt] 与 v1[1]相等

    for(int i=1; i<cnt; i++)
    {
        mn=min(mn,max(max(v[i],v1[i+1]),u[i]+u1[i+1]+tmp));//拆环上边的直径取一个min
    }

    ans=max(ans,mn);

    //printf("%lld\n",ans);
    if(ans%2==0)
        printf("%lld.0\n",ans/2);
    else
        printf("%lld.5\n",ans/2);

    return 0;
}
