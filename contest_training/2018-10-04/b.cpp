//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
char s[Nmax];
int n;
int main()
{
#ifdef test
#endif

    while(~scanf("%s",s+1))
    {
        n=strlen(s+1);
        int cnt=0;

        for(int i=1; i<=n; i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                cnt++;
        }

        if(cnt==0)
        {
            printf("1\n");
            continue;
        }

        if(s[1]!='a' && s[1]!='e' && s[1]!='i' && s[1]!='o' && s[1]!='u')
        {
            printf("0\n");
            continue;
        }

        int t=(cnt+1)>>1;
        int now=0;
        int i;

        for(i=1; i<=n; i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                now++;

            if(now==t)
                break;
        }

        int ans=1;

        for(i=i+1; i<=n; i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                break;

            ans++;
        }

        printf("%d\n",ans);
    }

    return 0;
}


