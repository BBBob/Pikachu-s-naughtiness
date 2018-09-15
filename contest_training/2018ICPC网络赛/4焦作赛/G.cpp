//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
const ll mod = 1e9+7;
char s[Nmax];
ll a,b,c,inv[Nmax];
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
inline void init()
{
    inv[1]=1ll;
    inv[2] = inv[mod % 2] * (mod - mod / 2) % mod;
    c=get_euler(mod);
}

int main()
{
    int t,len,flag;
    ll ans;
    scanf("%d",&t);
    init();
    while(t--)
    {
        memset(s,0,sizeof(s));
        scanf("%s",s);
        flag=0,b=0;
        len=strlen(s);

        for(int i=0; i<len; i++)
        {
            b=b*10+s[i]-'0';

            if(b>c)
            {
                flag=1;
                b%=c;
            }
        }
        if(flag)
            ans=qpow(2LL,b+c);
        else 
            ans=qpow(2LL,b);
        printf("%lld\n",ans*inv[2]%mod);
    }

    return 0;
}
