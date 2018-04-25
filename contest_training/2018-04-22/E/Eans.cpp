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

int main()
{
#ifdef test
#endif

    //freopen("E.in","r",stdin);
    while(~scanf("%d",&n))
    {
        for(int i=0; i<n; i++)
        {
            ll x;
            scanf("%lld",&x);
            a[i]=x;
        }

        printf("%lld\n",Q(n-1,1));
    }

    return 0;
}


