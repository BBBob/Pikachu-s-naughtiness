#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int M = 1e4+7;
vector<pair<int,int> > vec[M];
int dp[M][4];//dp[i][0]为子树下的最长距离 dp[i][1]次长距离 dp[i][2]最长距离节点 dp[i][3]上方最长距离
int n;
void dfs(int u,int fa)
{
    dp[u][0]=dp[u][1]=dp[u][3]=0;

    for(int i=0; i<vec[u].size(); i++)
    {
        int v=vec[u][i].f,w=vec[u][i].s;

        //printf("ww%d\n",w);
        if(v==fa)
            continue;

        dfs(v,u);

        if(dp[v][0]+w>dp[u][0])
        {
            dp[u][1]=dp[u][0];
            dp[u][0]=dp[v][0]+w;
            dp[u][2]=v;
            //  printf("1111%d\n",dp[v][0]+w);
        }
        else if(dp[v][0]+w>dp[u][1])
            dp[u][1]=dp[v][0]+w;
    }
}
void dfs1(int u,int fa)
{
    for(int i=0; i<vec[u].size(); i++)
    {
        int v=vec[u][i].f,w=vec[u][i].s;

        if(v==fa)
            continue;

        if(dp[u][2]==v)
            dp[v][3]=max(dp[u][3]+w,dp[u][1]+w);
        else
            dp[v][3]=max(dp[u][3]+w,dp[u][0]+w);

        dfs1(v,u);
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
            vec[i].clear();

        for(int i=2; i<=n; i++)
        {
            int v,w;
            scanf("%d%d",&v,&w);
            vec[i].push_back(make_pair(v,w));
            vec[v].push_back(make_pair(i,w));
        }

        dfs(1,-1);
        dfs1(1,-1);

        for(int i=1; i<=n; i++)
            printf("%d\n",max(dp[i][0],dp[i][3]));
    }

    return 0;
}
