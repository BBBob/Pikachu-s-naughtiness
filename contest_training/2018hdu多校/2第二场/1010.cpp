#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define Lowbit(x)  x&(-x)

using namespace std;
const int N = 500005;

struct Node
{
    int v,order;
    bool operator < (Node const &k) {
        return v<k.v;
    }
};

int n;
int c[N];
int aa[N];
Node a[N];

void Update(int t,int val)
{
    for(int i=t; i<=n; i+=Lowbit(i))
        c[i] += val;
}

int getSum(int x)
{
    int ans=0;

    for(int i=x; i>0; i-=Lowbit(i))
        ans += c[i];

    return ans;
}

/*inline bool cmp(Node &a,Node &b)
{
    return a.v<b.v;
}*/

int main()
{
    long long x, y;
    int dif=0;

    //freopen("sample.in","r",stdin);
    while(~scanf("%d%I64d%I64d",&n,&x,&y))
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i].v);
            a[i].order=i;
        }

        sort(a+1,a+1+n);
        dif = 1;
        aa[a[1].order]=1;

        for(int i=2; i<=n; i++)
        {
            if(a[i].v!=a[i-1].v)
                dif++;

            aa[a[i].order]=dif;
        }

        memset(c,0,sizeof(c));
        long long ans=0;

        for(int i=1; i<=n; i++)
        {
            Update(aa[i],1);
            ans+=(long long)i-(long long)getSum(aa[i]);
            //cout<<ans<<endl;
        }

        ans = (x<y?ans*x:ans*y);
        printf("%I64d\n",ans);
    }

    return 0;
}
// 1 7 8 2 3 4 5  6
// 9 2 3 4 5 6 7 8 1
//5 1 4 2 3
//1 4 5 2 3