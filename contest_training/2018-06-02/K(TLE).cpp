//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
struct Node
{
    int x,y;
    Node(){ }
    Node(int x,int y):x(x),y(y){ }
    bool operator < (const Node &b) const
    {
        if(x==b.x)
            return y<b.y;
        return x<b.x;
    }
}a[Nmax];
map<Node,bool> flag;
int main()
{
    #ifdef test
    #endif
    //freopen("k.in","r",stdin);
    int n;
    while(~scanf("%d",&n))
    {
        flag.clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
            flag[Node(a[i].x,a[i].y)]=1;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int dx=a[i].x-a[j].x,dy=a[i].y-a[j].y;
                if(flag[Node(a[i].x-dy,a[i].y+dx)] && flag[Node(a[j].x-dy,a[j].y+dx)])
                {
                    //printf("get:\n");
                    //printf("%d %d\n",a[i].x,a[i].y);
                    //printf("%d %d\n",a[j].x,a[j].y);
                    //printf("%d %d\n",a[i].x-dy,a[i].y+dx);
                    //printf("%d %d\n",a[j].x-dy,a[j].y+dx);
                    ans++;

                }
                if(flag[Node(a[i].x+dy,a[i].y-dx)] && flag[Node(a[j].x+dy,a[j].y-dx)])
                {
                    ans++;
                    //printf("get:\n");
                    //printf("%d %d\n",a[i].x,a[i].y);
                    //printf("%d %d\n",a[j].x,a[j].y);
                    //printf("%d %d\n",a[i].x+dy,a[i].y-dx);
                    //printf("%d %d\n",a[j].x+dy,a[j].y-dx);
                }
            }
        }
        printf("%d\n",ans/4);
    }



    return 0;
}


