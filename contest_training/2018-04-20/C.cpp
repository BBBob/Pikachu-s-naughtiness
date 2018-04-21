#include <bits/stdc++.h>
using namespace std;
const int M = 1e5+7;
vector<int> vec[M];
stack<int> s;
int dfn[M],vis[M],low[M],scc[M],jo[M],in[M],tot=1,cnt=0;
void tarjan(int u)
{
    vis[u]=1;
    dfn[u]=low[u]=tot++;
    s.push(u);

    for(int i=0; i<vec[u].size(); i++)
    {
        int v=vec[u][i];

        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v])
            low[u]=min(low[u],dfn[v]);
    }

    if(low[u]==dfn[u])
    {
        scc[cnt]=1e9;

        while(1)
        {
            int tmp=s.top();
            s.pop();
            vis[tmp]=0;
            jo[tmp]=cnt;
            scc[cnt]=min(scc[cnt],tmp);

            if(tmp==u)
                break;
        }

        cnt++;
    }
}
int main()
{
    int n,m;
    memset(dfn,0,sizeof(dfn));
    memset(vis,0,sizeof(vis));
    memset(low,0,sizeof(low));
    memset(in,0,sizeof(in));
    scanf("%d%d",&n,&m);

    for(int i=0; i<m; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        vec[u].push_back(v);
    }

    for(int i=1; i<=n; i++)
        if(!dfn[i])
            tarjan(i);

    for(int i=1; i<=n; i++)
        for(int j=0; j<vec[i].size(); j++)
            if(jo[i]!=jo[vec[i][j]])
                in[jo[vec[i][j]]]++;

    int k=0,ans=0;

    for(int i=0; i<cnt; i++)
        if(!in[i])
            ans++;

    printf("%d\n",ans);

    for(int i=0; i<cnt; i++)
        if(!in[i])
        {
            k==0?printf("%d",scc[i]):printf(" %d",scc[i]);
            k=1;
        }

    printf("\n");
    return 0;
}
