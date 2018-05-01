//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
const int Lmax=30;
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
} lb[Nmax];
int pos[Nmax];
ll a[Nmax];
int n;
int fa[Nmax];
int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
inline void merge(int x,int y)
{
    int r1=find(x),r2=find(y); 
    if(r1>r2)
        swap(r1,r2);
    if(r1!=r2)
        fa[r2]=r1;
}
int used[Nmax];
ll ans[Nmax];
int main()
{
#ifdef test
#endif
    //freopen("E.in","r",stdin);
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=n;i++)
        scanf("%d",&pos[i]);

    for(int i=n;i>=1;i--)
    {
        int now=pos[i];
        used[now]=1;
        lb[now].insert(a[now]);
        if(used[now+1])
        {
            merge(now,now+1);
            lb[now].mergeFrom(lb[now+1]);
        }
        if(used[now-1])
        {
            merge(now-1,now);
            int f=find(now-1);
            lb[f].mergeFrom(lb[now]);
        }
        ans[i]=max(ans[i+1],lb[find(now)].queryMax()); 
    }
    for(int i=1;i<=n;i++)
        printf("%lld\n",ans[i]);
    return 0;
}


