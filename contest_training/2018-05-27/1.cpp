//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e3+7;
typedef long long ll;
int n;
int flag[Nmax],deep[Nmax];
int in[Nmax];
struct Edge{
    int x,y,w,next;
    Edge(){ }
    Edge(int x,int y,int w,int next):x(x),y(y),w(w),next(next){ }
}e[Nmax*2];
int V[Nmax];
int size;
inline void init()
{
    memset(V,-1,sizeof(V));
    memset(flag,0,sizeof(flag));
    memset(deep,0,sizeof(deep));
    deep[0]=-1;
    size=0;
}
inline void add(int x,int y,int w)
{
    e[++size]=Edge(x,y,w,V[x]);
    V[x]=size;
}
int dfs(int now,int fa)
{
    //printf("now:%d fa:%d\n",now,fa);
    if(in[now])
    {
        flag[now]=1; 
        in[now]=0;
        return 1;
    }
    in[now]=1; 
    for(int i=V[now];~i;i=e[i].next)
    {
        int y=e[i].y;
        if(y==fa)
            continue;
        int tt=dfs(y,now);
        if(flag[now]==1)
        {
            in[now]=0;
            return 2;
        }
        if(tt==1)
        {
            flag[now]=1;
            in[now]=0;
            return 1;
        }
        else if(tt==2)
        {
            in[now]=0;
            return 2;
        }
    }
    in[now]=0;
    return 0;
}
void dfs2(int now,int fa)
{
    deep[now]=deep[fa]+1;
    for(int i=V[now];~i;i=e[i].next)
    {
        int y=e[i].y;
        if(y==fa || flag[y])
            continue;
        dfs2(y,now); 
    }
}
int main()
{
    #ifdef test
    #endif
    //freopen("1.in","r",stdin);
    int t;
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++)
    {
        printf("Case #%d: ",cases);
        scanf("%d",&n);
        init();
        for(int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            //printf("%d %d\n",x,y);
            add(x,y,1);
            add(y,x,1);
        }
        dfs(1,0);
        for(int i=1;i<=n;i++)
        {
            if(flag[i])
            {
                dfs2(i,0);
            }
        }
        for(int i=1;i<=n;i++)
            printf("%d%c",deep[i],i==n?'\n':' ');
    }
    return 0;
}


