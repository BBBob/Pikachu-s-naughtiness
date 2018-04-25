#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);

    while(n--)
    {
        int t,ans=0,x;
        scanf("%d",&t);

        for(int i=0; i<t; i++)
        {
            scanf("%d",&x);
            ans=max(ans,x);
        }

        printf("%d\n",ans);
    }

    return 0;
}