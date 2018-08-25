#include<bits/stdc++.h>
using namespace std;
const int maxn=7e7+70;
typedef long long ll;

int arr[maxn],maxval[maxn],que[maxn],num[maxn];
int n,m,k,p,q,r,mod;

void getMax(int n,int k)
{
    int head=0,rear=0;

    for(int i=1; i<=n; i++)
    {
        while(rear>head&&arr[que[rear-1]]<=arr[i])
            rear--;

        que[rear++]=i;

        if(i<k)
            continue;

        while(que[head]<i-k+1)
            head++;

        maxval[i]=arr[que[head]];
    }
}
void getNum(int n,int k)
{
    int head=0,rear=0;

    for(int i=n; i>=1; i--)
    {
        while(rear>head&&arr[que[rear-1]]<=arr[i])
            rear--;

        que[rear++]=i;

        if(i>n-k+1)
            continue;

        while(que[head]>i+k-1)
            head++;

        num[i]=rear-head;
    }
}
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d%d%d%d%d%d",&n,&m,&k,&p,&q,&r,&mod);

        for(int i=1; i<=k; i++)
            scanf("%d",&arr[i]);

        for(int i=k+1; i<=n; i++)
            arr[i]=((ll)p%mod*arr[i-1]%mod+(ll)q%mod*i%mod+r%mod)%mod;

        getMax(n,m);
        getNum(n,m);
        long long b=0,a=0;

        for(int i=1; i<=n-m+1; i++)
        {
            b=b+(num[i]^i);
            a=a+(maxval[i+m-1]^i);
        }

        printf("%lld %lld\n",a,b);
    }

    return 0;
}