//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
const int N=10;
int main()
{
#ifdef test
#endif
    srand(time(NULL));
    int n;
    int t=2;

    while(t--)
    {
        n=(rand()%N) +1;
        printf("%d\n",n);

        for(int i=1; i<=n; i++)
            printf("%d ",rand()%1001);

        printf("\n");
    }

    return 0;
}


