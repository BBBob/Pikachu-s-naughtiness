//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
const ll mod=1e9+7LL;
int n;
ll a[Nmax];
ll Q(int n,ll t)
{
    if(n<0)
        return t;

    return (Q(n-1,t)+Q(n-1,(t*a[n])%mod))%mod;
}
inline ll work()
{
    ll last=0;
    ll add=0;
    ll ans=0;
    ll tmp;
    ans=1;

    for(int i=0; i<n; i++)
    {
        tmp=(a[i]*(last+add+1LL))%mod;
        ans=(ans+tmp)%mod;
        add=last%mod;
        last=tmp;
    }

    return ans;
}
int main()
{
#ifdef test
#endif

    //freopen("E.in","r",stdin);
    while(~scanf("%d",&n))
    {
        ll last=0;
        ll add=0;
        ll ans=0;
        ll tmp;
        ans=1;

        for(int i=0; i<n; i++)
        {
            scanf("%lld",&a[i]);
            a[i]%=mod;
            tmp=(a[i]*(last+add+1LL))%mod;
            ans=(ans+tmp)%mod;
            add=last%mod;
            last=tmp;
        }

        //printf("%lld\n",ans);

        printf("%lld\n",work());
        //printf("ans:%lld\n",Q(n-1,1));
        //printf("%lld\n",Q(n-1,1));
        //printf("myans:%lld\n",work());


    }

    return 0;
}


