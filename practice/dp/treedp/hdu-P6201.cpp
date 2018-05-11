#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int M= 1e5+7;
vector<pair<int,int> > vec[M];
int val[M],dp[M][2];
int ans;
void dfs(int u,int fa)
{
    dp[u][0]=val[u];
    dp[u][1]=-val[u];

    for(int i=0; i<vec[u].size(); i++)
    {
        int v=vec[u][i].f,w=vec[u][i].s;

        if(v==fa)
            continue;

        dfs(v,u);
        dp[u][0]=max(dp[u][0],dp[v][0]-w);
        dp[u][1]=max(dp[u][1],dp[v][1]-w);
    }

    ans=max(dp[u][0]+dp[u][1],ans);
}
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n;
        ans=0;
        scanf("%d",&n);

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&val[i]);
            vec[i].clear();
        }

        for(int i=1; i<n; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            vec[u].push_back(make_pair(v,w));
            vec[v].push_back(make_pair(u,w));
        }

        dfs(1,-1);
        printf("%d\n",ans);
    }

    return 0;
}
