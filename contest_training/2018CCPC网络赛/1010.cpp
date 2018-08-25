//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e5+7;
typedef long long ll;
struct Pos
{
    int x,y;
    ll val;
} a[Nmax];
int n,xmax,ymax;
bool cmp(const Pos&a,const Pos &b)
{
    if(a.x==b.x)
        return a.y>b.y;

    return a.x<b.x;
}
struct Node
{
    int l;
    int r;
    int data;
} tree[Nmax*4];
void init()
{
    for(int i=0; i<Nmax*4; i++)
        tree[i].l=tree[i].r=tree[i].data=0;
}
void push_up(int root)
{
    tree[root].data=max(tree[root<<1].data,tree[root<<1|1].data);
}
void build(int root,int l,int r)
{
    tree[root].l=l;
    tree[root].r=r;

    if(l==r)
    {
        tree[root].data=0;
        return;
    }

    if(l<r)
    {
        int mid=(l+r)>>1;
        build(root*2,l,mid);
        build(root*2+1,mid+1,r);
        push_up(root);
    }
}
void update(int root,int l,int r,ll data)
{
    if(tree[root].l==l && tree[root].r == r)
    {
        tree[root].data=data;
        return;
    }

    int mid=(tree[root].l+tree[root].r)>>1;

    if(mid<l)
        update(root<<1|1,l,r,data);
    else if(mid>=r)
        update(root<<1,l,r,data);
    else
    {
        update(root<<1,l,mid,data);
        update(root<<1|1,mid+1,r,data);
    }

    push_up(root);
}
ll query(int root,int l,int r)
{
    if(tree[root].l>=l && tree[root].r<=r)
        return tree[root].data;

    int mid=(tree[root].l+tree[root].r)>>1;
    ll ans=0;

    if(mid<l)
        ans=max(ans,query(root<<1|1,l,r));
    else if(mid>=r)
        ans=max(ans,query(root<<1,l,r));
    else
        ans=max(query(root<<1,l,mid),query(root<<1|1,mid+1,r));

    ans=max(ans,0LL);
    return ans;
}
vector<int> xv,yv;
int get_idx(int x)
{
    return lower_bound(xv.begin(),xv.end(),x)-xv.begin()+1;
}
int get_idy(int x)
{
    return lower_bound(yv.begin(),yv.end(),x)-yv.begin()+1;
}
ll dp[Nmax];
int main()
{
#ifdef test
#endif
    int t;
    //freopen("1010.in","r",stdin);
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        xv.clear();
        yv.clear();
        ymax=0;

        for(int i=1; i<=n; i++)
        {
            scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].val);
            xv.push_back(a[i].x);
            yv.push_back(a[i].y);
            ymax=max(ymax,a[i].y);
        }

        sort(xv.begin(),xv.end());
        sort(yv.begin(),yv.end());
        xv.erase(unique(xv.begin(),xv.end()),xv.end());
        yv.erase(unique(yv.begin(),yv.end()),yv.end());
        ymax=get_idy(ymax);
        sort(a+1,a+1+n,cmp);
        init();
        build(1,0,ymax);

        for(int i=1; i<=n; i++)
        {
            int yid=get_idy(a[i].y);
            ll ym=query(1,0,yid-1);
            ll now=ym+a[i].val;
            ll nowy=query(1,yid,yid);

            if(nowy<now)
                update(1,yid,yid,now);
        }

        printf("%lld\n",query(1,1,ymax));
    }

    return 0;
}

