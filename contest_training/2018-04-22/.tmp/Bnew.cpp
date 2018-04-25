//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
ll mod_pro(ll x,ll y,ll n) 
{ 
    ll ret=0,tmp=x%n; 
    while(y) 
    { 
        if(y&0x1)if((ret+=tmp)>n)ret-=n; 
        if((tmp<<=1)>n)tmp-=n; 
        y>>=1; 
    } 
    return ret; 
} 
//快速幂，求(a^b) % c
ll mood(ll a,ll b,ll c) 
{ 
    ll ret=1; 
    while(b) 
    { 
        if(b&0x1)ret=mod_pro(ret,a,c); 
        a=mod_pro(a,a,c); 
        b>>=1; 
    } 
    return ret; 
} 
ll ran() 
{ 
    ll ret=rand(); 
    return ret*rand(); 
} 
bool is_prime(ll n,int t) 
{ 
    if(n<2)return false; 
    if(n==2)return true; 
    if(!(n&0x1))return false; 
    ll k=0,m,a,i; 
    for(m=n-1;!(m&1);m>>=1,k++); 
    while(t--) 
    { 
        a=mood(ran()%(n-2)+2,m,n); 
        if(a!=1) 
        { 
            for(i=0;i<k&&a!=n-1;i++) 
                a=mod_pro(a,a,n); 
            if(i>=k)return false; 
        } 
    } 
    return true; 
}
inline int work(ll &x)
{
    if(x==4)
       return 0*printf("2 2\n");
    ll now=x>>1; 
    if(!(now&1))
        now--;
    while(now>0)
    {
        if(is_prime(now,30) && is_prime(x-now,30))
            return 0*printf("%lld %lld\n",now,x-now);
        now-=2;
    }

    return 0;
}
int main()
{
    #ifdef test
    #endif
    srand(time(NULL));
    int t;
    scanf("%d",&t);
    ll x;
    while(t--)
    {
        scanf("%lld",&x);
        work(x);

    }
    return 0;
}
