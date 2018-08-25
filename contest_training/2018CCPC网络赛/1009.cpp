//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e5+7;
typedef long long ll;
const ll mod=1e9+7LL;

ll sz[Nmax],ww[Nmax];
int head[Nmax],cnt,uu[Nmax],vv[Nmax],tot;
ll n;
struct edge
{
    int v,next;
    ll w;
} e[Nmax<<1];
void add(int u,int v,ll w)
{
    e[++cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}
void dfs(int u,int fa)
{
    sz[u]=1;

    for(int i=head[u]; ~i; i=e[i].next)
    {
        int v=e[i].v;
        ll w=e[i].w;

        if(v==fa)
            continue;

        uu[++tot]=u;
        vv[tot]=v;
        ww[tot]=w;
        dfs(v,u);
        sz[u]+=sz[v];
    }

    return ;
}

inline ll qpow(ll base,ll n)
{
    base%=mod;
    ll ans=1LL;

    while(n>0)
    {
        if(n&1)
            ans=ans*base%mod;

        base=base*base%mod;
        n>>=1;
    }

    return ans;
}
ll pw[Nmax];

inline void init()
{
    pw[0]=1;

    for(int i=1; i<Nmax; i++)
        pw[i]=(ll)i*pw[i-1]%mod;
}

inline ll get2(ll w,ll a)
{
    ll ans=a*(n-a)%mod;
    ans=ans*w%mod;
    ans=ans*2LL%mod;
    ans=(ll)ans*(n-1)%mod;
    ans=ans*pw[n-2]%mod;
    return ans;
}
int main()
{
#ifdef test
#endif
    //freopen("1.in","r",stdin);
    init();

    while(~scanf("%lld",&n))
    {
        tot=cnt=0;
        memset(head,-1,sizeof(head));

        for(int i=1; i<n; i++)
        {
            int x,y;
            ll z;
            scanf("%d%d%lld",&x,&y,&z);
            add(x,y,z);
            add(y,x,z);
        }

        dfs(1,-1);
        ll ans=0LL;

        for(int i=1; i<n; i++)
            ans=(ans+get2(ww[i],sz[vv[i]]))%mod;

        printf("%lld\n",ans);
    }

    return 0;
}


