#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long LL;
const int M = 1e5+7;
int n,m;
vector<pair<int,int>> G[M];
int sz[M];
LL sum[M];
void dfs(int u,int fa)
{
    sz[u]=1;
    sum[u]=0;

    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i].f,val=G[u][i].s;

        if(v==fa)
            continue;

        dfs(v,u);
        sum[u]+=(LL)(val*sz[v]);
        sum[u]+=sum[v];
        sz[u]+=sz[v];
    }
}
set<LL> st;
LL ans;
set<LL>::iterator it;
void dfs1(int u,int fa)
{
    it=st.upper_bound(m+sum[u]);

    if(it!=st.begin())
    {
        it--;
        ans=max(ans,*(it)-sum[u]);
    }

    st.insert(sum[u]);

    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i].f;

        if(v==fa)
            continue;

        dfs1(v,u);
    }

    st.erase(st.find(sum[u]));
}
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&m);
        ans=-1;

        for(int i=1; i<n; i++)
        {
            int a,b,d;
            scanf("%d%d%d",&a,&b,&d);
            G[a].push_back(make_pair(b,d));
            G[b].push_back(make_pair(a,d));
        }

        dfs(1,-1);
        dfs1(1,-1);
        printf("%lld\n",ans);
        st.clear();

        for(int i=0; i<=n; i++)
            G[i].clear();
    }

    return 0;
}
