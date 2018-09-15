//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
const ll mod = 1e9+7;
inline ll qpow(ll base,ll n)
{
    ll ans=1LL;
    base%=mod;

    while(n>0)
    {
        if(n&1)
            ans=ans*base%mod;

        base=base*base%mod;
        n>>=1;
    }

    return ans;
}
inline ll get_euler(ll n)
{
    ll ans=n;

    for(ll i=2; i*i<=n; i++)
        if(n%i==0)
        {
            ans=ans/i*(i-1);

            while(n%i==0)
                n/=i;
        }

    if(n>1)
        ans=ans/n*(n-1);

    return ans;
}

ll a,b,inv[4];
char s[maxn];
inline void init()
{
    inv[1]=1ll;
    inv[2] = inv[mod % 2] * (mod - mod / 2) % mod;
}
int main()
{
    int t;
    scanf("%d",&t);
    init();

    while(t--)
    {
        memset(s,0,sizeof(s));
        scanf("%s",s);
        ll d=get_euler(mod);
        int len=strlen(s),flag=0;
        b=0;

        for(int i=0; i<len; i++)
        {
            b=b*10+s[i]-'0';

            if(b>d)
                flag=1,b%=d;
        }

        ll ans=flag?mod_pow(2,b+d):mod_pow(2,b);
        printf("%lld\n",(ans*inv[2])%mod);
    }

    return 0;
}
