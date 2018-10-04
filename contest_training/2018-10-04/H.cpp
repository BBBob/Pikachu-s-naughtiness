#include <iostream>
#include <cstdio>

using namespace std;

int C,P,B;
int c,p,b;

inline int Pro(int x)
{
    if(x < 0)
        return -x;
    else
        return 0;
}

int main()
{
    while(~scanf("%d%d%d",&C,&P,&B))
    {
        scanf("%d%d%d",&c,&p,&b);
        C -= c;
        P -= p;
        B -= b;
        printf("%d\n",Pro(C)+Pro(P)+Pro(B));
    }

    return 0;
}
