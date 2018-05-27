//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=27;
typedef long long ll;
int n;
int mp[Nmax][Nmax];
struct Edge{
    int x,y,w,next;
    Edge(){ }
    Edge(int x,int y,int w,int next):x(x),y(y),w(w),next(next){ }
}e[Nmax*Nmax*2];
int V[Nmax];
int size;
inline void init()
{
    memset(V,-1,sizeof(V));
    size=0;
}
inline void add(int x,int y,int w)
{
    e[++size]=Edge(x,y,w,V[x]);
    V[x]=size;
}
int a[15];
int book[Nmax*Nmax];
int check(int x,int y,int z)
{
    a[3]=e[x].w,a[1]=e[y].w,a[2]=e[z].w; 
    memset(book,0,sizeof(book));
    if(book[e[x].x])
        return 0;
    else
        book[e[x].x]=1;
    if(book[e[x].y])
        return 0;
    else
        book[e[x].y]=1;
    if(book[e[y].x])
        return 0;
    else
        book[e[y].x]=1;
    if(book[e[y].y])
        return 0;
    else
        book[e[y].y]=1;
    if(book[e[z].x])
        return 0;
    else
        book[e[z].x]=1;
    if(book[e[z].y])
        return 0;
    else
        book[e[z].y]=1;
    int sum=0;
    for(int i=1;i<=3;i++)
    {
        sum+=a[i];
    }
    for(int i=1;i<=3;i++)
    {
        if(a[i]*2>=sum)
            return 0;
    }
    return 1;
}
int main()
{
    #ifdef test
    #endif
    //freopen("2.in","r",stdin);
    int t;
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++)
    {
        printf("Case #%d: ",cases);
        scanf("%d",&n);
        init();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&mp[i][j]);
                if(i<=j && mp[i][j])
                    add(i,j,mp[i][j]);
            }
        int ans=0;
        for(int i=1;i<=size;i++)
        {
            for(int j=i+1;j<=size;j++)
            {
                for(int k=j+1;k<=size;k++)
                {
                    if(check(i,j,k))
                        ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}


