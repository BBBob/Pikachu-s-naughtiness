#include <cstdio>
#include <algorithm>
using namespace std;
const int Nmax=10000005;
typedef long long ll;
ll prime[Nmax];
int is_prime[Nmax];
int prime_cnt;
int n;
ll ans[Nmax];
ll num[Nmax];
void get()
{
    for(int i=2;i<Nmax;i++)
        is_prime[i]=1;
    for(ll i=2;i<Nmax;i++)
    {
        if(is_prime[i])
            prime[++prime_cnt]=i;
        for(int j=1;j<=prime_cnt;j++)
        {
            if(i*prime[j]>=Nmax)
                break;
            is_prime[i*prime[j]]=0;
            if(i%prime[j]==0)
                break;
        }
    }
}

void init()
{
    for(int i=1;i<=prime_cnt;i++)
        num[prime[i]]=i;
    for(int i=2;i<Nmax;i++)
        num[i]=max(num[i],num[i-1]);
}
int main()
{
    get();
    init();
    while(~scanf("%d",&n))
    {
        ll res=0LL;
        for(int i=1;i<=n;i++)
        {
            ll p=num[n/i];
            if(p*(p-1)>0)
                res+=p*(p-1);
        }
        printf("%lld\n",res);
    }
    return 0;
}
