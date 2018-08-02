#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e5+7;
typedef long long ll;
int n;
ll a[Nmax];
struct Edge
{
    int x,y;
    Edge() { }
    Edge(int x,int y):x(x),y(y) { }
} e[Nmax*2];
int main()
{
#ifdef test
#endif
    int t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        ll sum=0;

        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&a[i]);
            sum=sum^a[i];
        }

        for(int i=1; i<n; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
        }

        if(!sum)
            printf("D\n");
        else
            printf("Q\n");
    }

    return 0;

}