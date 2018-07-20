//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=2e5+7;
typedef long long ll;
int n,m;
int L,R;
struct Q
{
    int l,r,id;
}q[Nmax];
long long Ans;
int pos[Nmax];
bool cmp(Q a,Q b)
{
    if(pos[a.l]==pos[b.l])
        return a.r<b.r;
    return pos[a.l]<pos[b.l];
}
int ct[Nmax];
int a[Nmax];
void add(int x)
{
    ct[a[x]]++;
    if(ct[a[x]]==1)
        Ans++;
}
void del(int x)
{
    ct[a[x]]--;
    if(ct[a[x]]==0)
        Ans--;
}
int ans[Nmax];
#define new
int main()
{
    #ifdef test
    #endif
    //freopen("10.in","r",stdin);
    while(~scanf("%d%d",&n,&m)) 
    {
        memset(ct,0,sizeof(ct));
        Ans=0;
        L=0,R=0;
        int sz=sqrt(2*n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            pos[i]=i/sz;
        }
        for(int i=n+1;i<=2*n;i++)
        {
            a[i]=a[i-n];
            pos[i]=i/sz;
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&q[i].l,&q[i].r);
            swap(q[i].l,q[i].r);
            q[i].r+=n;
            q[i].id=i;
        }
        sort(q+1,q+1+m,cmp);
        for(int i=1;i<=m;i++)
        {
#ifdef old
            while(L<q[i].l)
            {
                L++;
                add(L);
            }
            while(L>q[i].l)
            {
                del(L);
                L--;
            }
            while(R>q[i].r)
            {
                R--;
                add(R);
            }
            while(R<q[i].r)
            {
                del(R);
                R++;
            }
#endif
    #ifdef new
            while(L<q[i].l)
            {
                del(L);
                L++;
            }
            while(L>q[i].l)
            {
                L--;
                add(L);
            }
            while(R>q[i].r)
            {
                del(R);
                R--;
            }
            while(R<q[i].r)
            {
                R++;
                add(R);
            }
        #endif
            ans[q[i].id]=Ans;
        }
        for(int i=1;i<=m;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}


