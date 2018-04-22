#include <bits/stdc++.h>
using namespace std;
const int M = 1e5+7;
struct edge
{
    int v,w;
    edge(int _v,int _w) {
        v=_v;
        w=_w;
    }
};
vector<edge> e[M];
int ans[M],cnt=0;
void dfs(int u,int tot,int fa)
{
    for(int i=0; i<e[u].size(); i++)
    {
        if(e[u][i].v!=fa)
        {
            ans[cnt++]=(tot+e[u][i].w);
            dfs(e[u][i].v,tot+e[u][i].w,u);
        }
    }

    return ;
}
int main()
{
    int n,k,p;
    scanf("%d%d%d",&n,&p,&k);

    for(int i=1; i<n; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e[u].push_back(edge(v,w));
        e[v].push_back(edge(u,w));
    }

    dfs(p,0,-1);
    sort(ans,ans+cnt);
    printf("%d\n",ans[k-1]);
    return 0;
}
