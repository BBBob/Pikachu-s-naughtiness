//#define test
#include<bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
const int INF=1e9+7;
int V[Nmax];
int fa[Nmax];
struct Edge
{
    int from,to,w,next;
    Edge() {}
    Edge(int from,int to,int w,int next):from(from),to(to),w(w),next(next) {}
} e[Nmax<<1];
int dis[Nmax];
int edge_size;
int n,q;
inline void add(int x,int y,int w)
{
    e[++edge_size]=Edge(x,y,w,V[x]);
    V[x]=edge_size;
}
inline void init()
{
    edge_size=0;
    memset(V,-1,sizeof(V));
    for(int i=1; i<=n; i++)
        dis[i]=INF,fa[i]=0;
}
struct Dijkstra
{
    struct heap_node
    {
        int value, id;
        heap_node() {}
        heap_node(int value,int id):value(value),id(id) {}
        friend bool operator < (const heap_node &a,const heap_node &b)
        {
            return a.value>b.value;
        }
    };
    __gnu_pbds::priority_queue<heap_node> heap;
    __gnu_pbds::priority_queue<heap_node>::point_iterator p[Nmax];
    inline int solve(int start,int end,int &ans_size)
    {
        heap_node ht;
        heap.clear();
        dis[start]=0;
        for(int i=1; i<=n; i++)
            p[i]=heap.push(heap_node(dis[i],i));
        for(int i=1; i<=n; i++)
        {
            ht=heap.top();
            int now=ht.id;
            heap.pop();
            if(ht.value==INF)
                break;
            for(int i=V[now]; ~i; i=e[i].next)
            {
                int v=e[i].to;
                int w=e[i].w;
                if(dis[now]+w<dis[v])
                {
                    dis[v]=dis[now]+w;
                    fa[v]=now;
                    heap.modify(p[v],heap_node(dis[v],v));
                }
            }
        }
        //printf("%d\n",dis[end]);
        ans_size=0;

        while(end)
        {
            ans_size++;
            end=fa[end];
        }
        return dis[n];
    }
}dij;
int main()
{
    #ifdef test
    #endif
    freopen("1.in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        init();
        for(int i=2;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            add(1,i,x);
            add(i,1,x);
        }
        for(int i=3;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            add(i-1,i,x);
            add(i,i-1,x);
        }
        int cnt;
        int ans=dij.solve(1,n,cnt);
        cnt--;
        printf("cnt:%d\n",cnt);
        for(int i=1;i<=q;i++)
        {
            int x;
            scanf("%d",&x);

            printf("%d%c",ans+cnt*x,i==q?'\n':' ');
        }
        
    }
    return 0;
}


