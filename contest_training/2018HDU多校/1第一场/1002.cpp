#include <bits/stdc++.h>
using namespace std;
const int M = 1e5+7;
typedef long long ll;
struct node
{
    int q,p;
    bool operator < (const node & x) const {
        if(q>=p&&x.q<x.p)
            return true;

        if(q<p&&x.q>=x.p)
            return false;

        if(q>=p&&x.q>=x.p)
            return p<x.p;

        if(q<=p&&x.q<=x.p)
            return q>x.q;
    }
} s[M];
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n;
        ll ans=0;
        scanf("%d",&n);

        for(int i=1; i<=n; i++)
        {
            char ss[M];
            s[i].p=0,s[i].q=0;
            scanf("%s",ss);
            int l=strlen(ss);

            for(int j=0; j<l; j++)
            {
                if(ss[j]=='(')
                    s[i].q++;
                else if(ss[j]==')'&&s[i].q>0)
                    ans++,s[i].q--;
                else if(ss[j]==')'&&s[i].q==0)
                    s[i].p++;
            }
        }

        sort(s+1,s+n+1);
        int num=0;

        for(int i=2; i<=n; i++)
        {
            num+=s[i-1].q;

            if(s[i].p>num)
            {
                ans+=num;
                num=0;
            }
            else
            {
                ans+=s[i].p;
                num-=s[i].p;
            }
        }

        printf("%I64d\n",ans*=2);
    }

    return 0;
}