//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
const int Lmax=63;
const ll mod=10086LL;
int n;
struct LinearBasis
{
    ll a[Lmax+1];
    int len;
    ll ans;
    LinearBasis() {
        clear();
        len=0;
        ans=0;
    }

    inline void clear() {
        fill(a,a+Lmax+1,0);
    }
    void insert(ll t,ll w) {
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
                ans+=w;
                a[j]=t;
                break;
            }
        }
    }
    ll query()
    {
        return ans;
    }
    // 数组 x 表示集合 S，下标范围 [1...n]
   
} lb;
struct Node
{
    ll id,w;
}a[Nmax];
bool cmp(const Node&a,const Node&b)
{
    return a.w>b.w;
}
int main()
{
    #ifdef test
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&a[i].id,&a[i].w);
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
        lb.insert(a[i].id,a[i].w);
    printf("%lld\n",lb.query());
    return 0;
}


