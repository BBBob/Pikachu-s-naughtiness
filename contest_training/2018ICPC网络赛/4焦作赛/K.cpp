//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e4+7;
const int Vmax=1e4;
typedef long long ll;
const ll mod=1e9+7LL;
ll size,dp[Nmax*2],v[Nmax];
ll c,num,cnt;
inline void init()
{
    memset(dp,0,sizeof(dp));
    size=0;
    dp[0]=1;
}
int main()
{
    //freopen("k.in","r",stdin);
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        init();

        for(int i = 1; i <= n; i++)
        {
            scanf("%lld%lld",&c,&num);
            cnt=1;

            while(num--)
            {
                v[++size]=(ll)c*cnt;
                cnt<<=1;
            }
        }

        for(int i = 1; i <= size; i++)
            for(int j = Vmax; j>=0; j--)
                if(dp[j]>0 && v[i]+j<=Vmax)
                    dp[j+v[i]]=(dp[j+v[i]]+dp[j])%mod;

        while(q--)
        {
            scanf("%lld",&num);
            printf("%lld\n",dp[num]);
        }

    }

    return 0;
}
