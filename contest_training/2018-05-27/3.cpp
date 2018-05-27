//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
const ll mod=1e9+7LL;
int n,k;
ll x[Nmax],y[Nmax],C,D,E1,E2,F;
ll a[Nmax];
inline void scan()
{
    x[1]%=F;
    y[1]%=F;
    a[1]=(x[1]+y[1])%F;
    E1%=F,E2%=F;
    for(int i=2;i<=n;i++)
    {
        x[i]=(C*x[i-1]%F+D*y[i-1]%F+E1)%F;
        y[i]=(D*x[i-1]%F+C*y[i-1]%F+E2)%F;
        a[i]=(x[i]+y[i])%F;
    }
}
struct Matrix
{
    int n,m;
    ll map[5][5];
    Matrix(int x,int y)
    {
        n=x;m=y;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                map[i][j]=0LL;
    }
    Matrix operator * (const Matrix b)
    {
        Matrix c(n,b.m);
        if(m==b.n)
        {
            for(int i=1;i<=c.n;i++)
                for(int k=1;k<=m;k++)
                    for(int j=1;j<=c.m;j++)
                        c.map[i][j]=(c.map[i][j]+(map[i][k]*b.map[k][j])%mod)%mod;
            return c;
        }
        printf("error!!!!!!!!!!!!!!\n");   
        exit(0);
        return c;
    }
    void print(int nn,int mm)
    {
        //printf("n:%d m:%d\n",n,m);
        for(int i=1;i<=nn;i++)
            for(int j=1;j<=mm;j++)
                printf("%lld%c",map[i][j],j==mm?'\n':' ');
    }
    void show()
    {
        printf("n:%d m:%d\n",n,m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                printf("%lld%c",map[i][j],j==m?'\n':' ');
    }
};
ll work(ll b,int k)
{
    Matrix base(2,2);
    base.map[1][1]=b;
    base.map[2][1]=0LL;
    base.map[1][2]=1LL;
    base.map[2][2]=1LL;
    //base.show();
    Matrix ans(2,2);
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            ans.map[i][j]=i==j?1:0;
    //if(k==1)
        //return b;
    //k--;
    while(k>0)
    {
        if(k&1)
            ans=ans*base;
        base=base*base;
        k>>=1;
    }
    Matrix now(2,1);
    now.map[1][1]=0LL;
    now.map[2][1]=b;
    //now.show();
    //ans.show();
    ans=ans*now;
    //printf("%lld\n",ans.map[1][1]);
    return ans.map[1][1];
}
ll sum[Nmax];

int main()
{
    #ifdef test
    #endif
    //freopen("3.in","r",stdin);
    int t;
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++)
    {
        printf("Case #%d: ",cases);
        scanf("%d%d",&n,&k);
        scanf("%lld%lld%lld%lld%lld%lld%lld",&x[1],&y[1],&C,&D,&E1,&E2,&F); 
        sum[0]=0LL;
        scan();
        for(int i=1;i<=n;i++)    
            sum[i]=(sum[i-1]+work(i,k))%mod;
        ll ans=0LL;
        for(int i=1;i<=n;i++)
        {
            ans=(ans+(a[i]*(n-i+1LL)%mod)*sum[i]%mod)%mod;
            //printf("a[%d]:%lld sum[i]:%lld\n",i,a[i],sum[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}


