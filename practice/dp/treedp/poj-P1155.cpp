#include <iostream>
#include <cstdio>
#include <vector>
#define f first
#define s second
using namespace std;
const int M = 3e3+7;
const int inf = 1e9+7;
vector<pair<int,int> > vec[M];
int ans[M][M],val[M];
int n,m,cost;
int dfs(int u,int fa)
{
    int f=0;

    if(vec[u].size()==1&&vec[u][0].f==fa)
        return 1;

    for(int i=0; i<vec[u].size(); i++)
    {
        int v=vec[u][i].f;
        int w=vec[u][i].s;

        if(v==fa)
            continue;

        f+=dfs(v,u);

        for(int j=f; j>=1; j--)
        {
            for(int k=0; k<=j; k++)
                ans[u][j]=max(ans[u][j],ans[u][j-k]+ans[v][k]-w);
        }
    }

    return f;
}
int main()
{
    scanf("%d%d",&n,&m);

    for(int i=1; i<=(n-m); i++)
    {
        int k;
        scanf("%d",&k);

        while(k--)
        {
            int v,w;
            scanf("%d%d",&v,&w);
            vec[i].push_back(make_pair(v,w));
            vec[v].push_back(make_pair(i,w));
        }
    }

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            ans[i][j]=-inf;

    for(int i=(n-m+1); i<=n; i++)
        scanf("%d",&val[i]),ans[i][1]=val[i];

    dfs(1,-1);

    for(int i=n; i>=1; i--)
        if(ans[1][i]>=0)
        {
            printf("%d\n",i);
            break;
        }

    return 0;
}
