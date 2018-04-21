//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e3+7;
typedef long long ll;
int n;
int mp[Nmax][Nmax];
unordered_map<int,int> book;
inline int check()
{
    ll sum=0LL;
    ll ans=0LL;
    for(int i=1;i<=n;i++)
        sum+=mp[i][i];
    for(int i=1,j=n;i<=n;i++,j--)
        ans+=mp[j][i];
    if(ans==sum)
        return 1;
    return 0;

}
int main()
{
    #ifdef test
    #endif
    scanf("%d",&n);
    int now=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            mp[i][j]=++now;
    if(check())
        swap(mp[1][2],mp[1][1]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d%c",mp[i][j],j==n?'\n':' ');
    }
    return 0;
}


