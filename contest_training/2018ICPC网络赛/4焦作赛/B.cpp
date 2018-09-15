#include <iostream>
#include <cstring>

using namespace std;

const long long INF = (long long)1e18+9LL;
long long dp[7][1005];
long long dpx[7][1005];
int f[1005];
char s[15];

int main()
{
	int T;
//	int l;
	int n,m;
	long long k;
	long long ans;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		memset(dpx,0,sizeof(dpx));
		scanf("%d%d%lld",&n,&m,&k);
		for(int i=0;i<=m;i++)
		for(int j=0;j<=n;j++)
		{
			dp[i][j]=-INF;
			dpx[i][j]=INF;
		}
		for(int i=1;i<=n;i++)
		scanf("%d",&f[i]);
		getchar();
		scanf("%s",s);
		//for(int i=0;i<=m;i++)
		dpx[0][0]=dp[0][0]=k;
		ans=-INF;
		for(int i=1;i<=n;i++)
		{
			dpx[0][i]=dp[0][i]=k;
			for(int j = 0; j < m; j++)
			{
				dp[j+1][i]=-INF;
				dpx[j+1][i]=INF;
				if(j+1<=i-1)
				{
					dp[j+1][i]=max(dp[j+1][i],dp[j+1][i-1]);
					dpx[j+1][i]=min(dpx[j+1][i],dpx[j+1][i-1]);
				}
				//if(i<=j)continue;
				if(s[j]=='+')
				{
					dp[j+1][i]=max(dp[j+1][i],dp[j][i-1]+f[i]);
					//dp[j+1][i]=max(dp[j+1][i],dpx[j][i-1]+f[i]);
					//dpx[j+1][i]=min(dpx[j+1][i],dp[j][i-1]+f[i]);
					dpx[j+1][i]=min(dpx[j+1][i],dpx[j][i-1]+f[i]);
				}
				if(s[j]=='-')
				{
					dp[j+1][i]=max(dp[j+1][i],dp[j][i-1]-f[i]);
					//dp[j+1][i]=max(dp[j+1][i],dpx[j][i-1]-f[i]);
					//dpx[j+1][i]=min(dpx[j+1][i],dp[j][i-1]-f[i]);
					dpx[j+1][i]=min(dpx[j+1][i],dpx[j][i-1]-f[i]);
				}
				if(s[j]=='*')
				{
					dp[j+1][i]=max(dp[j+1][i],dp[j][i-1]*f[i]);
					dp[j+1][i]=max(dp[j+1][i],dpx[j][i-1]*f[i]);
					dpx[j+1][i]=min(dpx[j+1][i],dp[j][i-1]*f[i]);
					dpx[j+1][i]=min(dpx[j+1][i],dpx[j][i-1]*f[i]);
				}
				if(s[j]=='/'&&f[i]!=0)
				{
					dp[j+1][i]=max(dp[j+1][i],dp[j][i-1]/f[i]);
					dp[j+1][i]=max(dp[j+1][i],dpx[j][i-1]/f[i]);
					dpx[j+1][i]=min(dpx[j+1][i],dp[j][i-1]/f[i]);
					dpx[j+1][i]=min(dpx[j+1][i],dpx[j][i-1]/f[i]);
				}
				if(j==m-1&&dp[j+1][i]>ans&&dp[j+1][i]!=INF&&j+1<=i)
				{
					//cout<<i<<' '<<j<<' '<<dp[j+1][i]<<endl;
					ans=dp[j+1][i];
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}


