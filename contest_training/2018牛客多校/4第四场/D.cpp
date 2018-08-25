//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=200+7;
typedef long long ll;
int mp[Nmax][Nmax];

void init()
{
    mp[1][1]=1,mp[1][2]=0,mp[2][1]=1,mp[2][2]=-1;

    for(int t=4; t<=200; t+=2)
    {
        for(int i=t-1; i<=t; i++)
            mp[i][1]=1;

        for(int i=t-1; i<=t; i++)
            for(int j=2; j<=t; j++)
                mp[i][j]=-1;

        for(int i=1; i<t-1; i++)
            for(int j=t-1; j<=t; j++)
                mp[i][j]=1;

        mp[t][t]=0;
    }
}
int main()
{
#ifdef test
#endif
    int t,n;
    scanf("%d",&t);
    init();

    while(t--)
    {
        scanf("%d",&n);

        if(n&1)
            printf("impossible\n");
        else
        {
            printf("possible\n");

            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    printf("%d%c",mp[i][j],j==n?'\n':' ');
        }
    }

    return 0;
}