#include <bits/stdc++.h>
using namespace std;
const int M = 1e3+7;
const int inf = 1e9;
vector<int> vec[M];
int dp[M][210],bigest[M][210],n,m;//bigest表示该点花j元可以得到的最大攻击力 dp表示该点为根的树花j元可得到最大攻击力
void dfs(int u,int fa)
{
    if(vec[u].size()==1&&u!=1) //如果是叶子节点
    {
        for(int i=0; i<=m; i++)
            dp[u][i]=bigest[u][i];

        return ;
    }

    for(int i=0; i<=m; i++)
        dp[u][i]=inf;

    for(int i=0; i<vec[u].size(); i++)
    {
        int v=vec[u][i];

        if(v==fa)
            continue;

        dfs(v,u);

        for(int j=m; j>=0; j--) //子树总花费为j
        {
            int t=0;

            for(int k=0; k<=j; k++) //v节点为根节点的子树花费为k
                t=max(t,min(dp[u][j-k],dp[v][k]));

            dp[u][j]=t;
        }
    }

    for(int i=m; i>=0; i--) //在该节点安装大炮
        for(int j=0; j<=i; j++)
            dp[u][i]=max(dp[u][i-j]+bigest[u][j],dp[u][i]);
}
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        memset(bigest,0,sizeof(bigest));

        for(int i=1; i<=n; i++)
            vec[i].clear();

        for(int i=1; i<n; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        scanf("%d",&m);

        for(int i=1; i<=n; i++)
        {
            int k;
            scanf("%d",&k);

            for(int j=0; j<k; j++)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                bigest[i][x]=max(bigest[i][x],y);
            }
        }

        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                bigest[i][j]=max(bigest[i][j],bigest[i][j-1]);

        dfs(1,-1);
        printf("%d\n",dp[1][m]);
    }

    return 0;
}
