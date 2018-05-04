#include <bits/stdc++.h>
using namespace std;
const int Maxn = 110000;
typedef long long LL;
vector<int> vec[Maxn];
LL w[Maxn],down[Maxn],up[Maxn];
void dfs(int u,int f)
{
    for(int i=0; i<vec[u].size(); i++)
    {
        int v=vec[u][i];

        if(v!=f)
        {
            dfs(v,u);
            up[u]=max(up[u],up[v]);
            down[u]=max(down[u],down[v]);
        }
    }

    w[u]+=up[u]-down[u];

    if(w[u]>0)
        down[u]+=w[u];
    else
        up[u]-=w[u];

    return ;
}
int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
        scanf("%lld",&w[i]);

    dfs(1,-1);
    printf("%lld\n",up[1]+down[1]);
    return 0;
}
