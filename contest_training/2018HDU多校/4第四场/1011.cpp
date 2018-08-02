#include <bits/stdc++.h>
using namespace std;
int t,tot,pre,flagg,flag;
char s[510];
int main()
{
    scanf("%d",&t);

    while(t--)
    {
        memset(s,0,sizeof(s));
        scanf("%s",s);
        int l=strlen(s),kk;

        for(int i=0; i<l; i++)
        {
            if((i==0||s[i-1]=='+'||s[i-1]=='*')&&s[i]=='0')
                kk=1;
            else if((i==0||s[i-1]=='+'||s[i-1]=='*')&&s[i]!='0')
                kk=0;

            if(s[i]=='?'&&kk==0)
            {
                s[i]='1';
                i--;
            }
            else if(s[i]=='?'&&kk==1)
            {
                s[i]='+';
                i--;
            }
        }

        //cout<<s<<endl;
        if(s[0]=='+'||s[0]=='*'||s[l-1]=='+'||s[l-1]=='*')
        {
            printf("IMPOSSIBLE\n");
            continue;
        }

        tot=0,pre=-1,flag=0,flagg=1;

        for(int i=0; i<l; i++)
        {
            if(s[i]=='+'||s[i]=='*'||i==l-1)
            {
                if(i==l-1)
                    i++;

                if(i-pre==1)
                {
                    printf("IMPOSSIBLE\n");
                    flagg=0;
                    break;
                }
                else if(tot==i-pre-1&&tot!=1)
                {
                    printf("IMPOSSIBLE\n");
                    flagg=0;
                    break;
                }
                else if(flag==1&&i-pre-1!=1)
                {
                    printf("IMPOSSIBLE\n");
                    flagg=0;
                    break;
                }

                tot=0,pre=i,flag=0;
                //cout<<pre<<endl;
            }
            else
            {
                if(s[i]=='0')
                    tot++;

                if(i==pre+1&&s[i]=='0')
                    flag=1;
            }
        }

        if(flagg)
            printf("%s\n",s);
    }

    return 0;
}