#include <bits/stdc++.h>
using namespace std;
int pre[200],vis[200];
int find(int x)
{
    int r=x;

    while(r!=pre[r])
        r=pre[r];

    int i=x,j;

    while(i!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }

    return r;
}
void join(int x,int y)
{
    int fx=find(x);
    int fy=find(y);

    if(fx!=fy)
        pre[fy]=fx;
}
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(vis,0,sizeof(vis));

        for(int i=1; i<=n; i++)
            pre[i]=i;

        for(int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            join(u,v);
            vis[u]++;
            vis[v]++;
        }

        int tot=0,cnt=0;

        for(int i=1; i<=n; i++)
        {
            if(i==pre[i])
                tot++;

            if(vis[i]%2!=0)
                cnt++;
        }

        if(tot==1&&(cnt==0||cnt==2))
            printf("Zhen\n");
        else
            printf("Xun\n");
    }

    return 0;
}
