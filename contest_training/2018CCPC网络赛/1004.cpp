//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
ll a,b,c,n;
int main()
{
#ifdef test
#endif
    int t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%lld%lld",&n,&a);

        if(n==1)
        {
            b=5LL;
            c=a+b;

        }
        else if(n==2)
        {
            if(a&1)
            {
                ll tmp=a>>1;
                c=tmp*tmp+(tmp+1)*(tmp+1);
                b=c-1;
            }
            else
            {
                ll tmp=a>>1;
                tmp-=1;
                c=1+(tmp+1)*(tmp+1);
                b=c-2;
            }
        }
        else
        {
            b=-1;
            c=-1;
        }

        printf("%lld %lld\n",b,c);
    }

    return 0;
}


