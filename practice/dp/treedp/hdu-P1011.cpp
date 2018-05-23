#include <bits/stdc++.h>
using namespace std;
vector<int> vec[110];
int val[110],cost[110];
int ans[110][110];
int n,m;
void dfs(int u,int fa)
{
    for(int i=m; i>=cost[u]; i--)
        ans[u][i]=val[u];

    for(int i=0; i<vec[u].size(); i++)
    {
        int v=vec[u][i];

        if(v==fa)
            continue;

        dfs(v,u);

        for(int j=m; j>=cost[u]+1; j--)
        {
            for(int k=1; k<=(j-cost[u]); k++)
            {
                if(ans[v][k])
                    ans[u][j]=max(ans[u][j],ans[u][j-k]+ans[v][k]);
            }
        }
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==-1&&m==-1)
            break;

        memset(ans,0,sizeof(ans));

        for(int i=1; i<=n; i++)
        {
            vec[i].clear();
            scanf("%d%d",&cost[i],&val[i]);

            if(cost[i]%20==0)
                cost[i]/=20;
            else
                cost[i]=(cost[i]/20+1);

            //printf("%d\n",cost[i]);
        }

        for(int i=1; i<n; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        if(m==0)
        {
            printf("0\n");
            continue;
        }

        dfs(1,-1);
        printf("%d\n",ans[1][m]);
    }

    return 0;
}
