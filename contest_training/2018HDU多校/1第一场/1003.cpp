#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x,y,pos;
    bool operator < (node const &k) {
        return x<k.x;

        if(x==k.x)
            return y<k.y;
    }
} p[3007];
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n;
        scanf("%d",&n);

        for(int i=1; i<=3*n; i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            p[i].pos=i;
        }

        sort(p+1,p+3*n+1);

        for(int i=1; i<=3*n; i++)
        {
            if(i%3==0)
                printf("%d\n",p[i].pos);
            else
                printf("%d ",p[i].pos);
        }
    }

    return 0;
}