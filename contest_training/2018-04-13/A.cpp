//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
char s[Nmax];
inline int is_digit(char c)
{
    if(c>='0' && c<='9')
        return 1;

    return 0;
}
int main()
{
#ifdef test
#endif
    scanf("%s",s);
    int n=strlen(s);
    ll num=0LL,flag=1LL;;
    ll ans;

    for(int i=0; i<n; i++)
    {
        if(s[i]=='-')
            flag=-1LL;
        else if(is_digit(s[i]))
        {
            num=num*10LL+s[i]-'0';
            ans=num*flag;
        }
        else
        {
            num=0LL;
            flag=1LL;
        }
    }

    printf("%lld\n",ans);
    return 0;
}


