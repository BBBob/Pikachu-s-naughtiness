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

int d[Nmax];
ll get_ans(int n)
{
    ll ans=0LL;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(is_prime[i/__gcd(i,j)] && is_prime[j/__gcd(i,j)])
                ans++;
        }
    }
    return ans*2LL;
}
void init()
{
    for(int i=1;i<=prime_cnt;i++)
        num[prime[i]]=i-1;

    //int SUM=10000000;
    int SUM=10000000;
    for(int i=3;i<=SUM;i++)
    {
        ans[i]=0LL;
        if(is_prime[i])
        {
            ans[i]=(ll)num[i];
        }
        else
        {
            int now=i;
            for(int j=1;j<=prime_cnt&& prime[j]<=now && prime[j]*prime[j] <=now;j++)     
            {
                if(now%prime[j]==0)
                {
                    while(now%prime[j]==0)
                        now/=prime[j];
                    ans[i]+=num[prime[j]];
                }
            }
            if(now!=1)
                ans[i]+=num[now];
        }
    }
    for(int i=1;i<=SUM;i++)
    {
        //printf("ans[%d]:%lld\n",i,ans[i]);
        ans[i]=(ll)ans[i-1]+2*ans[i];
    }
}
int main()
{
    freopen("h.out","w",stdout);
    int ans_size=0;
    get();
    init();
    printf("ll ans[]={0");
    for(int i=1;i<=10000000;i++) 
    {
        if(i%10000==0)
        printf(",%lld",ans[i]);
    }
    printf("};");
    return 0;
    for(int i=1;i<=100;i++)
    {
        //printf("ans[%d]:%lld my:%lld\n",i,get_ans(i),ans[i]);
        if(get_ans(i)!=ans[i])
            printf("wrong: %d\n",i);
    }
    //for(int i=1;i<=100;i++)
        //printf("i:%d %lld\n",i, (get_ans(i)-get_ans(i-1) )/2 );
        //printf("i:%d %lld\n",i,get_ans(i)/2);
        //printf("i:%d %lld\n",i, (get_ans(i)-get_ans(i-1) )/2 );
    return 0;
    
    for(int i=1;i<=prime_cnt;i++)
    {
        if(prime[i]*i>Nmax)
        {
            ans_size=i-1;
            break;
        }
        d[i]=i-1;
    }
    for(int i=1;i<=ans_size;i++)
    {
        ans[i]=ans[i-1]+d[i];
    }
    while(~scanf("%d",&n))
    {
        printf("%lld\n",ans[n]);
    }
    return 0;
}
