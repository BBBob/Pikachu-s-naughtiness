#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int a,b;
        int c=0,d=0;
        int y=1;
        char s[10];
        memset(s,0,sizeof(s));
        scanf("%d%d%s",&a,&b,s);

        if(a-8<0)
            a=a-8+24;
        else
            a-=8;

        int l=strlen(s);

        if(l==5)
        {
            c=s[4]-'0';

            if(s[3]=='-')
                y=-1;
        }
        else if(l==7)
        {
            c=s[4]-'0';
            d=s[6]-'0';
            d*=6;

            if(s[3]=='-')
                y=-1;
        }
        else if(l==8)
        {
            c=s[4]-'0';
            c*=10;
            c+=s[5]-'0';
            d=s[7]-'0';
            d*=6;

            if(s[3]=='-')
                y=-1;
        }
        else if(l==6)
        {
            c=s[4]-'0';
            c*=10;
            c+=s[5]-'0';

            if(s[3]=='-')
                y=-1;
        }

        if(d!=0)
        {
            if(y==1)
            {
                if(b+d>=60)
                {
                    b=b+d-60;

                    if(a==23)
                        a=0;
                    else
                        a++;
                }
                else
                    b=b+d;
            }
            else
            {
                if(b-d<0)
                {
                    b=b-d+60;

                    if(a==0)
                        a=23;
                    else
                        a--;
                }
                else
                    b=b-d;
            }
        }

        if(c!=0)
        {
            if(y==1)
            {
                if(c+a>=24)
                    a=c+a-24;
                else
                    a=c+a;
            }
            else
            {
                if(a-c<0)
                    a=a-c+24;
                else
                    a=a-c;
            }
        }

        if(a<10&&b<10)
            printf("0%d:0%d\n",a,b);
        else if(a<10&&b>=10)
            printf("0%d:%d\n",a,b);
        else if(a>=10&&b<10)
            printf("%d:0%d\n",a,b);
        else if(a>=10&&b>=10)
            printf("%d:%d\n",a,b);
    }

    return 0;
}