#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
//typedef  __int128 ll;
//typedef unsigned long long ll;
typedef  long long ll;
ll rand_Number(ll e){
    return rand()%e+1;;
}
ll mult_mod(ll a,ll b,ll c){
    a %= c;
    b %= c;
    ll res = 0;
    while(b){
        if(b & 1){
            res += a;
            res %= c;
        }
        a <<= 1;
        if(a >= c)
            a %= c;
        b >>= 1;
    }
    return res;
}

//a^u % num
ll getRemainder(ll a,ll u, ll num){
    ll cur = 1;
    ll nxt = a;
    nxt%=num;
    while (u>0) {
        if (u&1) {
            //cur = cur*nxt%num;
            cur = mult_mod(cur, nxt, num);
        }
        //nxt =  nxt*nxt%num;
        nxt = mult_mod(nxt, nxt, num);
        u = u>>1;
    }
    return cur%num;
}


bool checkPrime(ll num){
    if (num == 2 || num==3 || num==5 || num==7 || num==11 || num==13) {
        return true;
    }
    if (num < 2 || !(num&1) || num==4) {
        return false;
    }
    ll u = num-1;
    int S = 20; //检测次数
    while (!(u&1)) {
        u>>=1;
    }
    for (int i = 0; i < S; i++) {
        ll a = rand_Number(num-1);
        ll x = getRemainder(a, u, num);
        ll y = x;
        ll tu = u;
        x%=num;
        while (tu < num) {
            //y=x*x%num;
            y = mult_mod(x, x, num);;
            if (y == 1 && x != 1 && x != num-1) {
                return false;
            }
            x = y;
            tu<<=1;
        }
        if (x != 1) {
            return false;
        }
    }
    return true;
}
ll prime[Nmax];
int IS_prime[Nmax];
int prime_cnt;
int n;
void get()
{
    for(int i=2;i<Nmax;i++)
        IS_prime[i]=1;
    for(long long i=2;i<Nmax;i++)
    {
        if(IS_prime[i])
            prime[++prime_cnt]=i;
        for(int j=1;j<=prime_cnt;j++)
        {
            if(i*prime[j]>=Nmax)
                break;
            IS_prime[i*prime[j]]=0;
            if(i%prime[j]==0)
                break;
        }
    }
}


inline int work(ll &x)
{
    if(x==4)
       return 0*printf("2 2\n");
    for(int i=2;i<=prime_cnt;i++)
    {
        ll now=x-prime[i];
        if(now>=Nmax)
        {
            if(now%6==5 || now%6==1)
                if(checkPrime(now))
                    return 0*printf("%lld %lld\n",prime[i],now);
        }
        else
        {
            if(IS_prime[now])
                return 0*printf("%lld %lld\n",prime[i],now);
        }

    }
    return 0;
}
int main()
{
    #ifdef test
    #endif
    //freopen("1.in","r",stdin);
    srand(time(NULL));
    int t;
    get();
    scanf("%d",&t);
    ll x;
    while(t--)
    {
        scanf("%lld",&x);
        work(x);

    }
    return 0;
}
