//#define test
/*
 *题目是HackerRank的 prime xor
 *然而HackerRank上没有题目编号
 *所以又在ECNU上交了,并重新给文件命名
 *
 */
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
const ll mod=1e9+7LL;
const int Kmax=8207;
int n;
ll num[Kmax];
int a[Nmax];
vector<int> v;
ll dp[2][Nmax];
int is_prime[Kmax];
ll prime[Kmax];
int prime_cnt;
void get()
{
    for(int i=2; i<Kmax; i++)
        is_prime[i]=1;

    for(int i=2; i<Kmax; i++)
    {
        if(is_prime[i])
            prime[++prime_cnt]=i;

        for(int j=1; j<=prime_cnt; j++)
        {
            if(i*prime[j]>=Kmax)
                break;

            is_prime[i*prime[j]]=0;

            if(i%prime[j]==0)
                break;
        }
    }
}
int main()
{
#ifdef test
#endif
    // HackerRank上有t组数据
    //int t;
    //scanf("%d",&t);
    get();

    //while(t--)
    //{
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        memset(dp,0,sizeof(dp));
        v.clear();//不要忘记初始化..
        int now=0;

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            num[a[i]]++;
        }

        dp[now^1][0]=1;

        for(int i=3500; i<=4500; i++)
            if(num[i])
                v.push_back(i);

        for(int i=0; i<(int)v.size(); i++)
        {
            for(int j=0; j<Kmax; j++)
            {
                dp[now][j]=(dp[now^1][j]*(1LL+num[v[i]]/2)%mod+(dp[now^1][j^v[i]]*((num[v[i]]+1LL)/2))%mod)%mod;
                //后半部分中((num[v[i]]+1)/2)不要忘记最外层括号,否则不能取整除,会WA
            }

            now^=1;
        }

        ll ans=0LL;

        for(int i=0; i<Kmax; i++)
            if(is_prime[i])
                ans=(ans+dp[now^1][i])%mod;

        printf("%lld\n",ans);
    //}

    return 0;
}


