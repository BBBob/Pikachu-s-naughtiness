#include <iostream>
#include <cstdio>

using namespace std;

int dp[2][100011];
int ans[100011];
const int MOD = 1000000007;

int main()
{
    int k,Q;
    int l,r;
    int i;
    scanf("%d%d",&Q,&k);
    dp[0][0] = 1;

    for(i = 1; i <= k - 1; i++)
        dp[0][i] = (dp[0][i-1] + dp[1][i-1]) % MOD;

    for(i = k; i <= 100000; i++)
    {
        dp[0][i] = (dp[0][i-1] + dp[1][i-1]) % MOD;
        dp[1][i] = dp[0][i-k] % MOD;
    }

    ans[0]=1;

    for(i=1; i<=100000; i++)
        ans[i] = (ans[i-1] + (dp[0][i] + dp[1][i])  % MOD) % MOD;

    /*for(i=1;i<=10;i++)
    cout<<dp[0][i]+dp[1][i]+dp[2][i]<<' ';
    cout<<endl;*/
    for(i = 1; i<= Q; i++)
    {
        scanf("%d%d",&l,&r);
        printf("%d\n",(ans[r]-ans[l-1]+MOD)%MOD);
    }

    return 0;
}
