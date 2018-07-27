#include <ext/rope>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_cxx;

rope<int> T;
int n,m,p,q;
int main()
{
    scanf("%d%d",&n,&m);

    for(int i = 1; i <= n; i++)
        T.append(i);

    for(int i=1; i<=m; i++)
    {
        scanf("%d%d",&p,&q);
        p--;
        T=T.substr(p,q)+T.substr(0,p)+T.substr(p+q,n-p-q);
    }

    for(int i=0; i<n; i++)
        printf("%d ",T.at(i));

    return 0;
}