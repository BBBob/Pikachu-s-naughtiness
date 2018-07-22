#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6+7;
typedef long long ll;
vector<ll> v[MAX],cnt[MAX],now[MAX];
ll mp[MAX];
int main()
{
    int n,m,q,i,j,x1,x2,y1,y2;
    ll vv;
    while(~scanf("%d%d%d",&n,&m,&q))
    {
        for(i=1;i<=n*m;i++) mp[i]=i;
        random_shuffle(mp+1,mp+1+n*m);
        for(i=0;i<=n+1;i++)
        {
            v[i].resize(m+5);
            cnt[i].resize(m+5);
            now[i].resize(m+5);
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%lld",&v[i][j]);
                v[i][j]=mp[v[i][j]];
                now[i][j]=0;
                cnt[i][j]=0;
            }
        }
        while(q--)
        {
            scanf("%d%d%d%d%lld",&x1,&y1,&x2,&y2,&vv);

            now[x1][y1]+=mp[vv];
            now[x1][y2+1]-=mp[vv];
            now[x2+1][y1]-=mp[vv];
            now[x2+1][y2+1]+=mp[vv];

            cnt[x1][y1]++;
            cnt[x1][y2+1]--;
            cnt[x2+1][y1]--;
            cnt[x2+1][y2+1]++;
        }
        int ans=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                now[i][j]+=now[i-1][j]+now[i][j-1]-now[i-1][j-1];
                cnt[i][j]+=cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1];
                if(now[i][j]!=cnt[i][j]*v[i][j]) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
