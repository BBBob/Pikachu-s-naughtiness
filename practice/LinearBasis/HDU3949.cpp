//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
const int Lmax=63;
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
        getM();
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

        getM();
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
} lb;
ll a[Nmax];
int main()
{
#ifdef test
#endif
    //freopen("1.in","r",stdin);
    int t;
    scanf("%d",&t);

    for(int cases=1; cases<=t; cases++)
    {
        scanf("%d",&n);
        printf("Case #%d:\n",cases);
        lb.clear();

        for(int i=1; i<=n; i++)
        {
            ll x;
            scanf("%lld",&x);
            lb.insert(x);
        }

        lb.getM();
        //lb.show();
        int q;
        scanf("%d",&q);
        ll k;

        while(q--)
        {
            scanf("%lld",&k);
            printf("%lld\n",lb.Kth(k));
        }
    }

    return 0;
}


