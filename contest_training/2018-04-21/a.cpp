//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e3+7;
typedef long long ll;
int n;
int mp[Nmax][Nmax];
inline void print(int x,int y)
{
    return;
    printf("(%d,%d)\n",x,y);
}
int main()
{
#ifdef test
#endif
    scanf("%d",&n);
    int now=0;
    int x,y;
    int lastx=2,lasty=n;
    if(!(n&1))
    {
        x=1,y=n;
        while(now<n*n)
        {
            while(x>1 && y>1 && now<n*n &&!mp[x-1][y-1])
            {
                x--;y--;
                print(x,y);
                mp[x][y]=++now;
            }
            if(!mp[x][y])
            {
                print(x,y);
                mp[x][y]=++now;
            }
            x=lastx;y=lasty;
                mp[x][y]=++now;
            if(lasty==n && lastx!=n)
                lastx++;
            else
                lasty--;

        }

    }
    else
    {
        x=1,y=0;

        while(now<n*n)
        {
            while(y<n && now<n*n && !mp[x][y+1])
            {
                y++;
                mp[x][y]=++now;
                print(x,y);
            }

            if(!mp[x][y])
            {
                print(x,y);
                mp[x][y]=++now;
            }

            while(x<n && now<n*n && !mp[x+1][y])
            {
                x++;
                print(x,y);
                mp[x][y]=++now;
            }

            if(!mp[x][y])
            {
                print(x,y);
                mp[x][y]=++now;
            }

            //mp[x][y]=now++;
            while(y>1 && now<n*n && !mp[x][y-1])
            {
                y--;
                print(x,y);
                mp[x][y]=++now;
            }

            if(!mp[x][y])
            {
                print(x,y);
                mp[x][y]=++now;
            }

            //mp[x][y]=now++;
            while(x>1 && now<n*n && !mp[x-1][y])
            {
                x--;
                print(x,y);
                mp[x][y]=++now;
            }

            if(!mp[x][y])
            {
                print(x,y);
                mp[x][y]=++now;
            }

            //mp[x][y]=now++;
        }

    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            printf("%d%c",mp[i][j],j==n?'\n':' ');
    }

    return 0;
}


