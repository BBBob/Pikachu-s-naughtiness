#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        LL k,m;
        scanf("%lld%lld",&k,&m);
        k+=1;
        LL ans=k;
        ans%=(6*m);
        ans*=(k+1);
        ans%=(6*m);
        ans*=(k+2);
        ans%=(6*m);
        ans/=6;
        printf("%lld\n",ans);
    }

    return 0;
}
