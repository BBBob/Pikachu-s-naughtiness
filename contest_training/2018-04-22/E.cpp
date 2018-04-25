//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
const ll mod=1e9+7LL;
int n;
int main()
{
#ifdef test
#endif

    //freopen("E.in","r",stdin);
    while(~scanf("%d",&n))
    {
        ll ans=1;

        for(int i=0; i<n; i++)
        {
            ll x;
            scanf("%lld",&x);
            ans=(ans*(x+1LL))%mod;
        }

        printf("%lld\n",ans);
    }

    return 0;
}


