//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e5+7;
typedef long long ll;
ll a[Nmax];
inline void print(int x=1)
{
    if(x)
        printf("Kan\n");
    else
        printf("Li\n");
}
int n,q;
ll ans;
inline int check()
{
    //ll ans=0LL;
    //for(int i=1;i<=n;i++)
        //ans^=a[i];
    if(!ans)
        return 0;
    return 1;
}
int main()
{
    #ifdef test
    #endif
    //freopen("1.in","r",stdin);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    int pos;
    ll val;
    for(int i=1;i<=n;i++)
    {
        ans^=a[i];
    }
    while(q--)
    {
        scanf("%d%lld",&pos,&val);
        ans^=a[pos];
        a[pos]=val;
        ans^=a[pos];
        if(check())
            print();
        else
            print(0);
    }
    return 0;
}


