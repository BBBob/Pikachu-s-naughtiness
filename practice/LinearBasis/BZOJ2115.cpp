//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e5+7;
const int Lmax=63;
typedef long long ll;
int n,m;
struct Edge
{
    int from,to;
    ll w;
    int next;
    Edge() { }
    Edge(int from,int to,ll w,int next):from(from),to(to),w(w),next(next) { }
} e[Nmax<<1];
int size;
int V[Nmax];
inline void add(int x,int y,ll w)
{
    e[++size]=Edge(x,y,w,V[x]);
    V[x]=size;
}
inline void init()
{
    memset(V,-1,sizeof(V));
}
struct LinearBasis
{
    ll a[Lmax+1];
    int len;
    LinearBasis() {
        clear();
        len=0;
    }

    LinearBasis(ll *x, int n) {
        build(x,n);
    }
    inline void clear() {
        fill(a,a+Lmax+1,0);
    }
    void insert(ll t) {
        for(int j=Lmax; j>=0; j--) {
            if(!t)
                return;

            if(!(t & (1LL<<j)))
                continue;

            if(a[j])
                t^=a[j];
            else {
                for(int k=0; k<j; k++)
                    if(t & (1LL<<k))
                        t^=a[k];

                for(int k=j+1; k<=Lmax; k++)
                    if(a[k] & (1LL<<j))
                        a[k]^=t;

                a[j]=t;
                break;
            }
        }
    }

    // 数组 x 表示集合 S，下标范围 [1...n]
    void build(ll *x, int n) {
        fill(a,a+Lmax+1,0);

        for(int i=1; i<=n; i++)
            insert(x[i]);

    }

    ll queryMax() {
        ll res=0;

        for(int i=0; i<=Lmax; i++)
            res^=a[i];

        return res;
    }

    void mergeFrom(const LinearBasis &other) {
        for(int i=0; i<=Lmax; i++)
            insert(other.a[i]);
    }

    static LinearBasis merge(const LinearBasis &a, const LinearBasis &b) {
        LinearBasis res=a;

        for(int i=0; i<=Lmax; i++)
            res.insert(b.a[i]);

        return res;
    }
    inline ll Kth(ll k) {
        ll ans=0LL;

        if(len!=n)
            k--;

        if(k>=(1LL<<len))
            return -1;

        for(int i=0; i<=Lmax; i++) {

            ans^=(k&1)*a[i];
            k>>=1;
        }

        return ans;
    }
    inline void getM() {
        len=0;

        //获取线性基的模并且将空项删除
        for(int i=0; i<=Lmax; i++)
            if(a[i])
                a[len++]=a[i];

        fill(a+len,a+Lmax+1,0);
        //printf("len:%d\n",len);
    }
    inline void print(ll x) {
        int tmp[Lmax+1];

        for(int i=0; i<=Lmax; i++)
            tmp[i]=x&1,x>>=1;

        for(int i=Lmax; i>=0; i--)
            printf("%d",tmp[i]);

        printf("\n");
    }
    inline void show() {
        for(int i=0; i<len; i++)
            print(a[i]);
    }
    ll queryMaxWith(ll x) {
        ll ans=x;

        for(int i=0; i<=Lmax; i++)
            ans=max(ans,ans^a[i]);

        return ans;
    }
} lb;
int vis[Nmax];
ll dis[Nmax];
vector<ll> circle;
inline void dfs(int now,int fa)
{
    vis[now]=1;

    for(int it=V[now]; ~it; it=e[it].next)
    {
        int to=e[it].to;

        if(to==fa)
            continue;

        if(!vis[to])
        {
            dis[to]=dis[now]^e[it].w;
            dfs(to,now);
        }
        else
            circle.push_back(dis[now]^dis[to]^e[it].w);
    }
}
int main()
{
#ifdef test
#endif
    //freopen("1.in","r",stdin);
    scanf("%d%d",&n,&m);
    init();

    for(int i=1; i<=m; i++)
    {
        int x,y;
        ll d;
        scanf("%d%d%lld",&x,&y,&d);
        add(x,y,d);
        add(y,x,d);
    }
    dfs(1,0);
    for(auto it:circle) 
        lb.insert(it);
    printf("%lld\n",lb.queryMaxWith(dis[n]));
    return 0;
}


