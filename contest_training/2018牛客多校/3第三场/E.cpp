#include <bits/stdc++.h>
using namespace std;
const int M = 1e6+7;
char s[M];
int nxt[M],n;
void get_next()
{
    nxt[0]=-1;
    int i=0,j=-1;

    while(i<n)
    {
        if(j==-1||s[i]==s[j])
        {
            ++i;
            ++j;
            nxt[i]=j;
        }
        else
            j=nxt[j];
    }
}
int main()
{
    scanf("%s",s);
    n=strlen(s);
    get_next();

    if(n%(n-nxt[n])==0)
    {
        printf("%d\n",n-nxt[n]);

        for(int i=0; i<n-nxt[n]; i++)
        {
            printf("%d",n/(n-nxt[n]));

            for(int j=i; j<n; j+=(n-nxt[n]))
                printf(" %d",j);

            printf("\n");
        }
    }
    else
    {
        printf("%d\n",n);

        for(int i=0; i<n; i++)
            printf("1 %d\n",i);
    }

    return 0;
}