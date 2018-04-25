//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
const ll mod=1e9+7LL;
struct ODT
{
    struct Node
    {
        int l,r;
        mutable ll val;
        Node() {}
        Node(int l,int r=-1,ll val=0):l(l),r(r),val(val) {}
        friend bool operator < (const Node& a,const Node& b) {
            return a.l<b.l;
        }
    };
    set<Node> s;
    ODT(int n,ll x=0) {
        s.insert(Node(1,n,x));
    }
    inline set<Node>::iterator split(int pos) {
        auto it=s.lower_bound(Node(pos));

        if(it!=s.end() && it->l==pos)
            return it;

        --it;

        if(pos > it->r)
            return s.end();

        int l=it->l,r=it->r;
        ll val=it->val;
        s.erase(it);
        s.insert(Node(l,pos-1,val));
        return s.insert(Node(pos, r, val)).first;
    }
    inline void add(int l,int r,ll v=1) {
        split(l);
        auto itr=split(r+1),itl=split(l);

        for(; itl!=itr; ++itl)
            itl->val += v;
    }
    inline void modify(int l,int r,ll val=0LL) {
        split(l);
        auto itr=split(r+1),itl=split(l);
        s.erase(itl,itr);
        s.insert(Node(l,r,val));
    }
    vector<pair<ll,int>> vp;
    inline ll rank(int l,int r,int k,bool reversed=0) {
        if(reversed)
            k=r-l+2-k;

        split(l);
        auto itr=split(r+1),itl=split(l);
        vp.clear();

        for(; itl!=itr; ++itl)
            vp.push_back({itl->val,itl->r-itl->l+1});
        sort(vp.begin(),vp.end());

        for(auto i:vp) {
            k-=i.second;

            if(k<=0)
                return i.first;
        }

        return -1;
    }
    inline ll pow(ll base,ll n,ll mod) {
        base%=mod;
        ll ans=1LL;

        while(n>0) {
            if(n&1)
                ans=ans*base%mod;

            base=base*base%mod;
            n>>=1;
        }

        return ans;
    }
    inline ll sum(int l,int r,int ex,ll mod) {
        split(l);
        auto itr=split(r+1),itl=split(l);
        ll ans=0LL;

        for(; itl!=itr; itl++)
            ans=(ans+((ll)(itl->r-itl->l+1)*pow(itl->val,ex,mod)%mod))%mod;

        return ans;
    }
};
int n,m;
ll seed,vmax;
ll rnd()
{
    ll ret=seed;
    seed=(seed*7+13)%mod;
    return ret;
}
ll a[Nmax];
int main()
{
#ifdef test
#endif
    scanf("%d%d%lld%lld",&n,&m,&seed,&vmax);
    ODT odt(n);

    for(int i=1; i<=n; i++)
    {
        a[i]=(rnd()%vmax)+1;
        odt.modify(i,i,a[i]);
    }

    for(int i=1; i<=m; i++)
    {
        int op=(rnd()%4)+1;
        int l=(rnd()%n)+1;
        int r=(rnd()%n)+1;

        if(l > r)
            swap(l, r);

        ll x,y;

        if(op == 3)
            x = (rnd() % (r - l + 1)) + 1;
        else
            x = (rnd() % vmax) + 1;

        if(op == 4)
            y = (rnd() % vmax) + 1;

        if(op==1)
            odt.add(l,r,x);
        else if(op==2)
            odt.modify(l,r,x);
        else if(op==3)
            printf("%lld\n",odt.rank(l,r,x));
        else if(op==4)
            printf("%lld\n",odt.sum(l,r,x,y));
    }



    return 0;
}


