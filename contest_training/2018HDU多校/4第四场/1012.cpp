#include <bits/stdc++.h>
using namespace std;
const int M =1e5+7;
int a[M];
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n;
        scanf("%d",&n);

        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);

        printf("%d\n",(int)sqrt(abs(a[n]-a[1])));
    }

    return 0;
}