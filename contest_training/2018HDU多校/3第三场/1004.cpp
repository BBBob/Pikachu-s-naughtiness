#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int x;
        scanf("%d",&x);

        if(x==1)
            printf("5\n");
        else
            printf("%d\n",x+5);
    }

    return 0;
}