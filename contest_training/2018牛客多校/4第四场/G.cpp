#include <bits/stdc++.h>
using namespace std;
const int M = 1e5+7;
int t,n,m;
int a[M];
struct node
{
    int x,num;
    bool operator < (const node & k) const {
        if(num!=k.num)
            return num>k.num;

        return x>k.x;
    }
} p[M];
struct  nd
{
    int ans,m;
} pp[M];
map<int,int> mp;
int main()
{
    //freopen("r.in","r",stdin);
    //freopen("r.out","w",stdout);
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&m);

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            mp[a[i]]++;
        }

        sort(a+1,a+n+1);
        n=unique(a+1,a+n+1) - a;
        n--;

        for(int i=1; i<=n; i++)
        {
            p[i].x=a[i];
            p[i].num=mp[a[i]];
        }

        sort(p+1,p+n+1);
        int last=-1,cnt=-1,tot=0,cn=0,prenum=-1,kk=1;

        for(int i=1; i<=n; i++)
        {
            cnt++;
            last=max(last,p[i].x);

            if(p[i].num!=p[i+1].num||i==n)
            {
                pp[kk].m=tot+cnt+(prenum-p[i].num+1)*cn;
                pp[kk].ans=last;
                kk++;
                tot+=(prenum-p[i].num)*cn;
                cn+=cnt+1;
                prenum=p[i].num;
                cnt=-1;
            }
        }

        //for(int i=1;i<kk;i++) printf("%d %d\n",pp[i].ans,pp[i].m);
        if(m<pp[1].m)
            printf("-1\n");
        else
        {
            for(int i=1; i<kk; i++)
            {
                if(m<pp[i].m)
                {
                    printf("%d\n",pp[i-1].ans);
                    break;
                }

                if(i==kk-1)
                    printf("%d\n",pp[i].ans);
            }
        }

        mp.clear();
    }

    return 0;
}