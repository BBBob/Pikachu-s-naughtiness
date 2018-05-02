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
    vector<int> bit;
    inline ll rank(ll x)//求出x在异或集合中是第几小
    {
        bit.clear();
        for(int i=0;i<=Lmax;i++)
            if(a[i])
                bit.push_back(i);
        ll ans=0LL;
        for(int i=0;i<(int)bit.size();i++)
        {
            if(x&(1<<bit[i]))
            {
                ans|=(1<<i);
            }
        }
        return ans;
    }
} lb;
ll a[Nmax];
ll qpow(ll base,ll n)
{
    base%=mod;
    ll ans=1LL;
    while(n>0)
    {
        if(n&1)
            ans=(ans*base)%mod;
        base=base*base%mod;
        n>>=1;
    }
    return ans;
}
int main()
{
    #ifdef test
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        lb.insert(a[i]);
    }
    ll q;
    scanf("%lld",&q);     
    ll rk=lb.rank(q);
    lb.getM();//注意求秩一定要放在求rank之后,否则会先改变线性基中a_i的位置使得位置错误
    printf("%lld\n",(rk*qpow(2LL,n-lb.len)+1)%mod);
    return 0;
}


