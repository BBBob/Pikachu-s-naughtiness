#include <bits/stdc++.h>
using namespace std;
vector<int> vec[6100];
int w[6100],dp[6100][2];
void dfs(int u,int f)
{
    for(int i=0; i<vec[u].size(); i++)
    {
        int v=vec[u][i];

        if(v!=f)
        {
            dfs(v,u);
            dp[u][0]+=max(dp[v][0],dp[v][1]);
            dp[u][1]+=dp[v][0];
        }
    }

    dp[u][1]+=w[u];
    return ;
}
int main()
{
    int n;

    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&w[i]);
            dp[i][0]=dp[i][1]=0;
            vec[i].clear();
        }

        int u,v;

        while(1)
        {
            scanf("%d%d",&u,&v);

            if(u==0&&v==0)
                break;

            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        dfs(1,-1);
        printf("%d\n",max(dp[1][0],dp[1][1]));
    }

    return 0;
}
