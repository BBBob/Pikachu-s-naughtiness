//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e3+7;
typedef long long ll;
char s[Nmax];
int n,k;
int base[Nmax];
char ans[Nmax];
int dp[Nmax][2][Nmax];
int dfs(int now,int lead,int left)
{
    if(dp[now][lead][left]!=-1)
        return dp[now][lead][left];

    if(now>n)
    {
        if(!left)
        {
            dp[now][lead][left]=1;
            return 1;
        }

        dp[now][lead][left]=0;
        return 0;
    }

    char b=ans[now];

    if(b!='?')
    {
        int g=dfs(now+1,b=='0' && lead,(left+base[n-now]*(ans[now]-'0'))%k);
        dp[now][lead][left]=g;
        return g;
    }

    for(int i=lead; i<=9; i++)
    {
        ans[now]=i+'0';
        int g=dfs(now+1,i==0 && lead,(left+base[n-now]*i)%k);

        if(g==1)
        {
            dp[now][lead][left]=g;
            return 1;
        }

        ans[now]=b;
    }

    dp[now][lead][left]=0;
    return 0;
}
int main()
{
#ifdef test
#endif

    //freopen("e.in","r",stdin);
    while(~scanf("%s%d",s+1,&k))
    {
        memset(ans,0,sizeof(ans));
        memset(dp,-1,sizeof(dp));
        n=strlen(s+1);
        base[0]=1%k;

        for(int i=1; i<n; i++)
            base[i]=base[i-1]*10%k;

        for(int i=1; i<=n; i++)
            ans[i]=s[i];

        int flg=(s[1]=='?')?1:0;
        int g=dfs(1,flg,0);

        if(g==0)
            printf("*\n");
        else
            printf("%s\n",ans+1);
    }

    return 0;
}


