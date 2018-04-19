#include <bits/stdc++.h>
#define inf 0x7fffffff
#define T 2001
using namespace std;
int n,head[2005],q[2005],dis[2005],from[2005],a[1005],mp[1001][1001],cnt,ans;
bool inq[2005];
struct data
{
    int from,to,next,v,c;
} e[1000001];
void ins(int u,int v,int w,int c)
{
    cnt++;
    e[cnt].from=u;
    e[cnt].to=v;
    e[cnt].v=w;
    e[cnt].c=c;
    e[cnt].next=head[u];
    head[u]=cnt;
}
void insert(int u,int v,int w,int c)
{
    ins(u,v,w,c);
    ins(v,u,0,-c);
}
bool spfa()
{
    for(int i=0; i<=T; i++)
        dis[i]=inf;

    int t=0,w=1,i,now;
    dis[0]=q[0]=0;
    inq[0]=1;

    while(t!=w)
    {
        now=q[t];
        t++;

        if(t==2001)
            t=0;

        for(int i=head[now]; i; i=e[i].next)
        {
            if(e[i].v&&dis[e[i].to]>dis[now]+e[i].c)
            {
                from[e[i].to]=i;
                dis[e[i].to]=dis[now]+e[i].c;

                if(!inq[e[i].to])
                {
                    inq[e[i].to]=1;
                    q[w++]=e[i].to;

                    if(w==2001)
                        w=0;
                }
            }
        }

        inq[now]=0;
    }

    if(dis[T]==inf)
        return 0;

    return 1;
}
void mcf()
{
    int i,x=inf;
    i=from[T];

    while(i)
    {
        x=min(e[i].v,x);
        i=from[e[i].from];
    }

    i=from[T];

    while(i)
    {
        e[i].v-=x;
        e[i^1].v+=x;
        ans+=x*e[i].c;
        i=from[e[i].from];
    }
}
void build(int k)
{
    cnt=1;
    memset(head,0,sizeof(head));
    ans=0;

    for(int i=1; i<=n; i++)
        insert(0,i,1,0);

    for(int i=1; i<=n; i++)
        insert(n+i,T,1,0);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            insert(i,j+n,inf,k*mp[i][j]);
}
int main()
{
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d",&mp[i][j]);

    build(1);

    while(spfa())
        mcf();

    printf("%d\n",ans);
    build(-1);

    while(spfa())
        mcf();

    printf("%d",-ans);
    return 0;
}
