//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e8+7;
typedef long long ll;
long long prime[Nmax];
long long phi[Nmax];
int IS_prime[Nmax];
int prime_cnt;
int n;
void get()
{
    for(int i=2;i<Nmax;i++)
        IS_prime[i]=1;
    for(long long i=2;i<Nmax;i++)
    {
        if(IS_prime[i])
            prime[++prime_cnt]=i;
        for(int j=1;j<=prime_cnt;j++)
        {
            if(i*prime[j]>=Nmax)
                break;
            IS_prime[i*prime[j]]=0;
            if(i%prime[j]==0)
                break;
        }
    }
}


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
inline ll mood(ll a,ll b,ll& c) 
{ 
    ll ret=1; 
    while(b) 
    { 
        if(b&0x1)
            ret=(a*ret)%c;
            //ret=mod_pro(ret,a,c); 
        a=a*a%c;
        //a=mod_pro(a,a,c); 
        b>>=1; 
    } 
    return ret; 
} 
inline ll ran() 
{ 
    ll ret=rand(); 
    return ret*rand(); 
} 
inline bool is_prime(ll n,int t) 
{ 
    if(n<2)return false; 
    if(n==2)return true; 
    if(!(n&0x1))return false; 
    if(!(n%6==5 || n%6==1))
        return false; 
    ll k=0,m,a,i; 
    for(m=n-1;!(m&1);m>>=1,k++); 
    while(t--) 
    { 
        a=mood(ran()%(n-2)+2,m,n); 
        if(a!=1) 
        { 
            for(i=0;i<k&&a!=n-1;i++) 
                a=a*a%n;
                //a=mod_pro(a,a,n); 
            if(i>=k)return false; 
        } 
    } 
    return true; 
}
inline int work(ll &x)
{
    if(x==4)
       return 0*printf("2 2\n");
    for(int i=2;prime[i]<x && i<=prime_cnt;i++)
    {
        ll now=x-1LL*prime[i];
        printf("%lld\n",prime[i]);
        //printf("%lld",x);
        if(prime[i]==43)
        {
            printf("yes:%lld\n",now);
            return 0;
        }
        if(now<Nmax && IS_prime[now])
            return 0*printf("%lld %lld\n",prime[i],now);
        else if(is_prime(now,30))
            return 0*printf("%lld %lld\n",prime[i],now);
    }
    

    //ll now=prime[prime_cnt]+2LL;
    //while(1)
    //{
        //if(is_prime(now,10) && is_prime(x-now,10))
            //return 0*printf("%lld %lld\n",now,x-now);
        //now+=2LL;
    //}
    ll m=x>>1;
    while(m>0)
    {
        if(is_prime(m,10) && is_prime(x-m,10))
            return 0*printf("%lld %lld\n",m,x-m);
        m>>=1;
    }
    //printf("yes\n");
    //fflush(stdout);
    //ll now=x>>1; 
    //ll now=sqrt(x)+2; 
    //if(!(now&1))
        //now--;
    //while(now>0)
    //{
        //if(is_prime(now,5) && is_prime(x-now,5))
            //return 0*printf("%lld %lld\n",now,x-now);
        //now-=2;
        ////printf("now:%lld\n",now);
    //}

    return 0;
}
inline int work(ll &x,int t)
{
    if(x==4)
    {
        printf("2 2\n");
        return 0;
    }
    ll now=x>>1;
    while(t--)
    {
        ll i=rand()%(now+3) +3LL;
        if(!(i&1))
        {
            t++;
            continue;
        }
        if(i<Nmax && IS_prime[i])
        {
            if(x-i<Nmax && IS_prime[x-i]) 
                return 0*printf("%lld %lld\n",i,x-i);
        }
        else if(is_prime(i,10))
        {
            if(is_prime(x-i,10))
                return 0*printf("%lld %lld\n",i,x-i);
        }
    }
    return 0;
}
int main()
{
    #ifdef test
    #endif
    freopen("b.in","r",stdin);
    get();
    srand(time(NULL));
    int t;
    scanf("%d",&t);
    ll x;
    while(t--)
    {
        scanf("%lld",&x);
        //printf("%lld\n",x);
        //return 0;
        work(x);
    }
    return 0;
    while(t--)
    {
        scanf("%lld",&x);
        work(x,10000000);
    
    }
    return 0;
}


