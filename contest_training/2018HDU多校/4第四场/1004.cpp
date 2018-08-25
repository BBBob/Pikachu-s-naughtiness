//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e2+7;
typedef long long ll;
int n;
ll m;
struct Node
{
    int x,y;
} a[Nmax];
bool cmp(const Node&a,const Node&b)
{
    return a.x*b.y>b.x*a.y;
    //return a.x>b.x;
}
inline int get()
{
    for(int i=1; i<=n; i++)
    {
        m=(ll)m*a[i].x/(a[i].x+a[i].y);

        if(m<=0)
            return i-1;
    }

    return n;
}
int main()
{
#ifdef test
#endif
    int t;
    //freopen("1004.in","r",stdin);
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%lld",&n,&m);

        for(int i=1; i<=n; i++)
            scanf("%d%d",&a[i].x,&a[i].y);

        sort(a+1,a+1+n,cmp);
        //for(int i=1;i<=n;i++)
        //printf("a:%d %d\n",a[i].x,a[i].y);
        printf("%d\n",get());
    }

    return 0;
}