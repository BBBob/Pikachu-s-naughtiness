//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
const int Lmax=63;
struct LinearBasis
{
    long long a[Lmax+1];

    LinearBasis() 
    {
        fill(a,a+Lmax+1,0);
    }

    LinearBasis(long long *x, int n) 
    {
        build(x,n);
    }

    void insert(long long t) 
    {
        for(int j=Lmax;j>=0;j--) 
        {
            if(!t)
                return;
            if(!(t & (1ll << j)))
                continue;
            if(a[j])
                t ^= a[j];
            else 
            {
                for(int k = 0; k < j; k++)
                    if(t & (1ll << k))
                        t ^= a[k];

                for(int k = j + 1; k <= Lmax; k++)
                    if(a[k] & (1ll << j))
                        a[k] ^= t;

                a[j] = t;
                break;
            }
        }
    }

    // 数组 x 表示集合 S，下标范围 [1...n]
    void build(long long *x, int n) 
    {
        fill(a,a+Lmax+1,0);
        for(int i=1;i<=n;i++)
            insert(x[i]);
    }

    long long queryMax() 
    {
        long long res=0;
        for(int i=0;i<=Lmax;i++)
            res^=a[i];
        return res;
    }

    void mergeFrom(const LinearBasis &other) 
    {
        for(int i=0;i<=Lmax;i++)
            insert(other.a[i]);
    }

    static LinearBasis merge(const LinearBasis &a, const LinearBasis &b) 
    {
        LinearBasis res=a;
        for(int i=0;i<=Lmax;i++)
            res.insert(b.a[i]);

        return res;
    }
}lb;
ll a[Nmax];
int main()
{
    #ifdef test
    #endif
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        lb.insert(a[i]);
    }
    printf("%lld\n",lb.queryMax());
    return 0;
}


