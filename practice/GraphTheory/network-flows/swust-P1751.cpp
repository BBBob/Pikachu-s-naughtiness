#include <bits/stdc++.h>
#define inf 0x7fffffff
#define T 2001
using namespace std;
int n,m,head[2005],q[2005],dis[2005],from[2005],a[1005],mp[1001][1001],cnt,ans;
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
int get(int i, int j)
{
    return (m + m + i - 2) * (i - 1) / 2 + j;
}
void build1(int k)
{
    cnt=1;
    memset(head,0,sizeof(head));
    ans=0;
    int num = get(n, n + m - 1);
    //printf("%d\n",num);
    int s = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m + i - 1; j++)
        {
            insert(get(i, j), num + get(i, j), 1, k*mp[i][j]);

            //printf("%d\n",get(i,j));
            if(i < n)
            {
                insert(num + get(i, j), get(i+1, j), 1, 0);
                insert(num + get(i, j), get(i+1, j+1), 1, 0);
            }
        }

    for(int i = 1; i <= m; i++)
        insert(s, i, 1, 0);

    for(int i = 1; i <= n + m -1; i++)
        insert(num + get(n, i), T, 1, 0);
}
void build2(int k)
{
    cnt=1;
    memset(head,0,sizeof(head));
    ans=0;
    //printf("%d\n",num);
    int s = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m + i - 1; j++)
        {
            //printf("%d\n",get(i,j));
            if(i < n)
            {
                insert(get(i, j), get(i+1, j), 1, k*mp[i][j]);
                insert(get(i, j), get(i+1, j+1), 1, k*mp[i][j]);
            }
        }

    for(int i = 1; i <= m; i++)
        insert(s, i, 1, 0);

    for(int i = 1; i <= n + m -1; i++)
        insert(get(n, i), T, inf, k*mp[n][i]);
}
void build3(int k)
{
    cnt=1;
    memset(head,0,sizeof(head));
    ans=0;
    //printf("%d\n",num);
    int s = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m + i - 1; j++)
        {
            //printf("%d\n",get(i,j));
            if(i < n)
            {
                insert(get(i, j), get(i+1, j), inf, k*mp[i][j]);
                insert(get(i, j), get(i+1, j+1), inf, k*mp[i][j]);
            }
        }

    for(int i = 1; i <= m; i++)
        insert(s, i, 1, 0);

    for(int i = 1; i <= n + m -1; i++)
        insert(get(n, i), T, inf, k*mp[n][i]);
}
int main()
{
    scanf("%d%d", &m, &n);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m + i - 1; j++)
            scanf("%d", &mp[i][j]);

    build1(-1);

    while(spfa())
        mcf();

    printf("%d\n",-ans);
    build2(-1);

    while(spfa())
        mcf();

    printf("%d\n",-ans);
    build3(-1);

    while(spfa())
        mcf();

    printf("%d\n",-ans);
    return 0;
}
