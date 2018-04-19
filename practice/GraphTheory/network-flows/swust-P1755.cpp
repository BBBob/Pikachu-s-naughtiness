#include <bits/stdc++.h>
#define inf 0x7fffffff
using namespace std;
int cnt,n,m,a,b,ans;
int from[2005],q[2005],dis[2005],head[2005],mp[1005][1005],T,s=0;
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

        if(t==T)
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

                    if(w==T)
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
int main()
{
    scanf("%d%d%d%d",&a,&b,&n,&m);
    cnt=1,ans=0;
    memset(head,-1,sizeof(head));
    int c=0,x,y;
    T=(n+1)*(m+1)+1;

    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
            mp[i][j]=++c;

    for(int i=0; i<=n; i++)
        for(int j=0; j<m; j++)
        {
            scanf("%d",&c);
            insert(mp[i][j],mp[i][j+1],1,-c);
            insert(mp[i][j],mp[i][j+1],inf,0);
        }

    for(int j=0; j<=m; j++)
        for(int i=0; i<n; i++)
        {
            scanf("%d",&c);
            insert(mp[i][j],mp[i+1][j],1,-c);
            insert(mp[i][j],mp[i+1][j],inf,0);
        }

    for(int i=0; i<a; i++)
    {
        scanf("%d%d%d",&c,&x,&y);
        insert(s,mp[x][y],c,0);
    }

    for(int i=0; i<b; i++)
    {
        scanf("%d%d%d",&c,&x,&y);
        insert(mp[x][y],T,c,0);
    }

    while(spfa())
        mcf();

    printf("%d\n",-ans);
    return 0;
}
