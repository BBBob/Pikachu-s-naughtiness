//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e5+7;
typedef long long ll;
int n,r; 

int V[Nmax];
struct Edge
{
    int x,y;
    int next;
    Edge(){ }
    Edge(int x,int y,int next):x(x),y(y),next(next){ }
}e[Nmax];
int size;
inline void add(int x,int y)
{
    e[++size]=Edge(x,y,V[x]);
    V[x]=size;
}
inline void init()
{
    size=0;
    memset(V,-1,sizeof(V));
}
int dfs(int now,int fa,int is)
{
    for(int i=V[now];~i;i=e[i].next)   
    {
        int y=e[i].y;
        if(y==fa)
            continue;
        if(!is)    
        {
            if(dfs(y,now,is^1))
                return 1;
        }
        else 
        {
            if(!dfs(y,now,is^1))
                return 0;
        }
    }
    if(!is) 
        return 0;
    else
        return 1;
}
int main()
{
    #ifdef test
    #endif
    //freopen("1.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d%d",&n,&r);
        for(int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            add(x,y);
            add(y,x);
        }
        if(dfs(r,0,0))
            printf("Gen\n");
        else
            printf("Dui\n");
    }
    return 0;
}


