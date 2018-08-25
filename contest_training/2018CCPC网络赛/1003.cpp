//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
int main()
{
#ifdef test
#endif
    int t;
    scanf("%d",&t);
    ll p;

    while(t--)
    {
        scanf("%lld",&p);

        for(int i=1; i<=p; i++)
            for(int j=1; j<=p; j++)
                printf("%d%c",1,j==p?'\n':' ');

        for(int i=1; i<=p; i++)
            for(int j=1; j<=p; j++)
                printf("%lld%c",(i-1)*(j-1)%p,j==p?'\n':' ');
    }

    return 0;
}


