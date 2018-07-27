#include <bits/stdc++.h>
using namespace std;
const int M = 1e5+7;
struct  node
{
    int l,r;
    bool operator < (const node & x) const {
        if(l!=x.l)
            return l<x.l;
        else
            return r>x.r;
    }
} p[M];
int main()
{
    int t,n,m,ans[M];
    set<int> st;
    scanf("%d",&t);

    while(t--)
    {
        st.clear();
        scanf("%d%d",&n,&m);

        for(int i=1; i<=n; i++)
            ans[i]=-1,st.insert(i);

        for(int i=1; i<=m; i++)
            scanf("%d%d",&p[i].l,&p[i].r);

        sort(p+1,p+m+1);
        int L=1,R=0;

        for(int i=1; i<=m; i++)
        {
            while(L<p[i].l)
            {
                if(ans[L]==-1)
                    ans[L]=1;
                else
                    st.insert(ans[L]);

                L++;
            }

            while(R<p[i].r)
            {
                R++;

                if(ans[R]==-1)
                {
                    ans[R]=*st.begin();
                    st.erase(ans[R]);
                }
            }
        }

        for(int i=1; i<=n; i++)
            printf("%d%s",ans[i]==-1?1:ans[i],i==n?"\n":" ");
    }

    return 0;
}