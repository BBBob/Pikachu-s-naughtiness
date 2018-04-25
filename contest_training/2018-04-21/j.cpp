#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 7;
typedef long long LL;
int a[M],b[M];
LL ans=0;
int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);

    sort(a,a+n);
    int tot=0;

    for(int i=0; i<n/2; i++)
    {
        b[tot++]=a[i];
        b[tot++]=a[n-1-i];
    }

    if(n%2!=0)
        b[tot++]=a[n/2];

    for(int i=1; i<n; i++)
        ans+=abs(b[i]-b[i-1]);

    ans+=abs(b[0]-b[n-1]);
    printf("%lld\n",ans);
    return 0;
}
