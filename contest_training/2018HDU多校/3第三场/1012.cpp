#include <bits/stdc++.h>
using namespace std;
char s[100][100];
int t,l,d,h;
int main()
{
    //freopen("r.in","r",stdin);
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d%d",&l,&d,&h);

        for(int i=1; i<=2*d+2*h+1; i++)
        {
            for(int j=1; j<=2*d+2*l+1; j++)
                s[i][j]='k';
        }

        for(int i=1; i<=2*d; i++)
        {
            for(int j=1; j<=2*d-i+1; j++)
                s[i][j]='.';
        }

        for(int i=1; i<=2*d; i++)
        {
            if(i%2!=0)
            {
                for(int j=2*d+2-i; j<=2*d+1-i+2*l+1; j++)
                {
                    if(j%2!=0)
                        s[i][j]='+';
                    else
                        s[i][j]='-';
                }
            }
            else
            {
                for(int j=2*d+2-i; j<=2*d+1-i+2*l+1; j++)
                {
                    if(j%2!=0)
                        s[i][j]='.';
                    else
                        s[i][j]='/';
                }
            }
        }

        for(int i=2*d+1; i<=2*d+2*h+1; i++)
        {
            if(i%2!=0)
            {
                for(int j=1; j<=2*l+1; j++)
                {
                    if(j%2!=0)
                        s[i][j]='+';
                    else
                        s[i][j]='-';
                }
            }
            else
            {
                for(int j=1; j<=2*l+1; j++)
                {
                    if(j%2!=0)
                        s[i][j]='|';
                    else
                        s[i][j]='.';
                }
            }
        }

        int tot=0;

        for(int i=2*h+2; i<=2*h+2*d+1; i++)
        {
            for(int j=2*l+2*d+1-tot; j<=2*l+2*d+1; j++)
                s[i][j]='.';

            tot++;
        }

        for(int i=1; i<=2*d+2*h+1; i++)
        {
            for(int j=1; j<=2*d+2*l+1; j++)
            {
                if(s[i][j]=='k')
                {
                    if(i%2!=0)
                    {
                        if(j%2!=0)
                            s[i][j]='+';
                        else
                            s[i][j]='.';
                    }
                    else
                    {
                        if(j%2!=0)
                            s[i][j]='|';
                        else
                            s[i][j]='/';
                    }
                }
            }
        }

        for(int i=1; i<=2*d+2*h+1; i++)
        {
            for(int j=1; j<=2*d+2*l+1; j++)
                printf("%c",s[i][j]);

            printf("\n");
        }
    }

    return 0;
}