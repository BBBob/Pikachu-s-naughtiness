#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T, n;
    long long ans;
    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        if(n%3==0)
        {
            ans = n/3;
            ans= ans*ans*ans;
            printf("%lld\n",ans);
        }
        else
        {
            if(n%4==0)
            {
                ans = n / 4;
                ans = ans*ans*ans*2;
                printf("%lld\n",ans);
            }
            else
                printf("-1\n");
        }
    }

    return 0;
}