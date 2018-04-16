//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=2e5+7;
typedef long long ll;
const ll INF=LLONG_MAX;
const ll boom=3037000500LL;
ll m;
int n,len;
ll deg[Nmax],freq[Nmax];
int q;
ll a,b;
ll pre_sum[Nmax],sum[Nmax];
inline void init()
{
    for(int i=1; i<=n; i++)
    {
        pre_sum[i]=pre_sum[i-1]+deg[i]*deg[i]*freq[i];
        sum[i]=sum[i-1]+freq[i];
    }
}
inline ll val(int s)
{
    return a*pre_sum[s]+b*m*(sum[n]-sum[s]);

}
int main()
{
#ifdef test
#endif
    //freopen("3.in","r",stdin);
    scanf("%lld%d",&m,&n);

    for(int i=1; i<=n; i++)
        scanf("%lld%lld",&deg[i],&freq[i]);

    init();
    scanf("%d",&q);

    while(q--)
    {
        scanf("%lld%lld",&a,&b);
        int l=1,r=n;
        int ans=0;

        while(l<=r)
        {
            int mid=(l+r)>>1;

            if(sqrt(a)*deg[mid]<=sqrt(b*m))
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }

        printf("%lld\n",val(ans));
    }

    return 0;
}


