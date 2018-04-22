#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a[110],b[110],s[110];

    while(scanf("%s",a)!=EOF)
    {
        int l=strlen(a);

        for(int i=0; i<l; i++)
            b[l-1-i]=a[i];

        if(strcmp(a,b)<0)
        {
            for(int i=l-1; i>=0; i--)
            {
                int x=b[i]-'0';
                int y=a[i]-'0';

                if(x-y>=0)
                    s[i]=(x-y)+'0';
                else
                {
                    int k=x-y+10;
                    s[i]=k+'0';
                    int kk=b[i-1]-'0';
                    kk-=1;
                    b[i-1]=kk+'0';
                }
            }

            //for(int i=0;i<l;i++) printf("%c",s[i]);
            //printf("\n");
        }
        else
        {
            for(int i=l-1; i>=0; i--)
            {
                int x=a[i]-'0';
                int y=b[i]-'0';

                if(x-y>=0)
                    s[i]=(x-y)+'0';
                else
                {
                    int k=x-y+10;
                    s[i]=k+'0';
                    int kk=a[i-1]-'0';
                    kk-=1;
                    a[i-1]=kk+'0';
                }
            }
        }

        int pos,flag=0;

        for(int i=0; i<l; i++)
        {
            if(s[i]!='0'&&flag==0)
            {
                flag=1;
                pos=i;
            }
        }

        if(flag==0)
            printf("YES\n");
        else
        {
            for(int i=0; i<l; i++)
                s[i]=s[i+pos];

            l-=pos;
            int tmp=0,flagg=0;
            vector<int> vec;

            for(int i=0; i<l; i++)
            {
                tmp=tmp*10+(s[i]-'0');

                if(tmp<9)
                    continue;

                if(vec.empty())
                    vec.push_back(tmp/9);

                if((!vec.empty()&&vec[0]!=tmp/9)||(i==l-1&&tmp%9!=0))
                {
                    flagg=1;
                    break;
                }

                tmp%=9;
            }

            if(flagg==0)
                printf("YES\n");
            else
                printf("NO\n");
        }

        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(s,0,sizeof(s));
    }

    return 0;
}