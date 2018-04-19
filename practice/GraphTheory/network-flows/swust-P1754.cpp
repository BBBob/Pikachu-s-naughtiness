#include<iostream>
#include<cstdio>
#define inf 0x7fffffff
#define T 2001
using namespace std;
int cnt,n,ans;
int from[2005],q[2005],dis[2005],head[2005],qq[2005];
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
int main()
{
    cnt=1,ans=0;
    scanf("%d",&n);
    double tot=0;

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&qq[i]);
        tot+=(double)qq[i];
    }

    tot=(int)(tot/(1.0*n));

    for(int i=1; i<=n; i++)
    {
        qq[i]=qq[i]-tot;
        //printf("%d\n",qq[i]);
    }

    for(int i=1; i<=n; i++)
    {
        if(qq[i]>0)
            insert(0,i,qq[i],0);
        else if(qq[i]<0)
            insert(i+n,T,-qq[i],0);

        if(i!=1&&i!=n)
        {
            insert(i,i+1,inf,1);
            insert(i,i-1,inf,1);
            insert(i,i+n+1,inf,1);
            insert(i,i+n-1,inf,1);
        }
    }

    insert(1,2,inf,1);
    insert(1,n,inf,1);
    insert(n,1,inf,1);
    insert(n,n-1,inf,1);
    insert(1,n+2,inf,1);
    insert(1,2*n,inf,1);
    insert(n,1+n,inf,1);
    insert(n,2*n-1,inf,1);

    while(spfa())
        mcf();

    printf("%d",ans);
    return 0;
}
