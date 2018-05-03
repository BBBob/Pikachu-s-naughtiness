#include <bits/stdc++.h>
using namespace std;
const int M = 2e5+7;
typedef long long LL;
int pre[M],num[M];
LL ans[M];
struct edge
{
    int u,v;
    LL w;
} E[M];
bool cmp(const edge &x,const edge &y)
{
    return x.w>y.w;
}
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
void join(int x,int y,LL z)
{
    int fx=find(x);
    int fy=find(y);
    ans[fx]+=num[fy]*z;
    ans[fy]+=num[fx]*z;

    if(fx!=fy)
    {
        pre[fy]=fx;
        num[fx]+=num[fy];
        ans[fx]=max(ans[fx],ans[fy]);
    }
}
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n;
        scanf("%d",&n);

        for(int i=1; i<=n; i++)
        {
            pre[i]=i;
            num[i]=1;
            ans[i]=0;
        }

        for(int i=1; i<n; i++)
            scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].w);

        sort(E+1,E+n,cmp);

        for(int i=1; i<n; i++)
            join(E[i].u,E[i].v,E[i].w);

        for(int i=1; i<=n; i++)
        {
            if(i==pre[i])
            {
                printf("%lld\n",ans[i]);
                break;
            }
        }
    }

    return 0;
}
