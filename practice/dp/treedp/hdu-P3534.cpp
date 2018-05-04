#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int M = 1e6+7;
int n;
int dp[M][6];
vector<pair<int,int>> vec[M];
void dfs(int u,int fa)
{
    dp[u][0]=dp[u][1]=0;
    dp[u][2]=dp[u][3]=1;
    dp[u][4]=dp[u][5]=0;

    for(int i=0; i<vec[u].size(); i++)
    {
        int v=vec[u][i].f,w=vec[u][i].s;

        if(v==fa)
            continue;

        dfs(v,u);

        if(dp[v][0]+w>dp[u][0])
        {
            dp[u][1]=dp[u][0];
            dp[u][3]=dp[u][2];
            dp[u][0]=dp[v][0]+w;
            dp[u][2]=dp[v][2];
            dp[u][5]=dp[u][4]=0;
        }
        else if(dp[v][0]+w==dp[u][0])
        {
            dp[u][5]+=(dp[v][2]*dp[u][2]);
            dp[u][2]+=dp[v][2];
            dp[u][4]=1;
        }
        else if(dp[v][0]+w>dp[u][1])
        {
            dp[u][1]=dp[v][0]+w;
            dp[u][3]=dp[v][2];
        }
        else if(dp[v][0]+w==dp[u][1])
            dp[u][3]+=dp[v][2];
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1; i<=n; i++)
            vec[i].clear();

        for(int i=1; i<n; i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            vec[x].push_back(make_pair(y,z));
            vec[y].push_back(make_pair(x,z));
        }

        dfs(1,-1);
        int Max=-1;

        for(int i=1; i<=n; i++)
        {
            if(dp[i][4]==1)
                Max=max(Max,2*dp[i][0]);
            else
                Max=max(Max,dp[i][0]+dp[i][1]);
        }

        //printf("%d %d\n",dp[1][0],dp[1][1]);
        int ans=0;

        for(int i=1; i<=n; i++)
        {
            if(dp[i][4]==1&&2*dp[i][0]==Max)
                ans+=dp[i][5];
            else if(dp[i][4]!=1&&dp[i][0]+dp[i][1]==Max)
                ans+=(dp[i][2]*dp[i][3]);
        }

        printf("%d %d\n",Max,ans);
    }

    return 0;
}
