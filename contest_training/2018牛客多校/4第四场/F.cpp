#include <bits/stdc++.h>
using namespace std;
char s[2007][2007];
int main()
{
    //freopen("r.in","r",stdin);
    //freopen("r.out","w",stdout);
    int t,m,n,x,y;
    scanf("%d",&t);

    while(t--)
    {
        memset(s,0,sizeof(s));
        scanf("%d%d",&n,&m);
        x=n/2+1;
        y=m/2+1;

        for(int i=0; i<n; i++)
            scanf("%s",s[i]);

        for(int i=0; i<n/2; i++)
        {
            for(int j=0; j<m/2; j++)
            {
                if(s[i][j]!=s[i][m-1-j]||s[i][j]!=s[n-1-i][m-1-j]||s[i][j]!=s[n-1-i][j]||s[i][m-1-j]!=s[n-1-i][m-1-j]||s[i][m-1-j]!=s[n-1-i][j]||s[n-1-i][j]!=s[n-1-i][m-1-j])
                {
                    if(n-i>x)
                        x=n-i;

                    if(m-j>y)
                        y=m-j;
                }
            }
        }

        if(n==x||m==y)
            printf("0\n");
        else
            printf("%d\n",(n-x)*(m-y));
    }

    return 0;
}