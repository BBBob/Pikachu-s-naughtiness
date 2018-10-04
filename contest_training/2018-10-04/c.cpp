//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e4+7;
typedef long long ll;
int cnt[1005];
int cntcnt[Nmax];
int a[Nmax];
int tmp[Nmax];
set<int> s;
int main()
{
#ifdef test
#endif
    int k,n;

    //freopen("c.in","r",stdin);

    while(~scanf("%d%d",&k,&n))
    {
        memset(cnt,0,sizeof(cnt));
        memset(cntcnt,0,sizeof(cntcnt));
        s.clear();

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }

        int empty_size=0;

        for(int i=1; i<=k; i++)
        {
            s.insert(cnt[i]);
            cntcnt[cnt[i]]++;

            if(!cnt[i])
                empty_size++;
        }

        if(empty_size>1)
        {
            printf("*\n");
            continue;
        }

        int kkk=0;

        for(auto it:s)
            tmp[++kkk]=it;

        //for(int i=1; i<=kkk; i++)
        //printf("%d ",tmp[i]);

        //printf("\n");

        if(s.size()>3)
        {
            printf("*\n");
            continue;
        }

        else if(s.size()==1)
        {
            printf("-1 +1\n");
            continue;
        }

        else if(s.size()==2)
        {

            if(tmp[2]==tmp[1]+2)
            {
                if(cntcnt[tmp[1]]==1 && cntcnt[tmp[2]]==1)
                {
                    int a1,a2;

                    for(int i=1; i<=k; i++)
                    {
                        if(cnt[i]==tmp[1])
                            a1=i;

                        if(cnt[i]==tmp[2])
                            a2=i;
                    }

                    printf("-%d +%d\n",a2,a1);

                }
                else
                    printf("*\n");

                continue;
            }

            if(tmp[2]!=tmp[1]+1)
            {
                printf("*\n");
                continue;
            }

            if(cntcnt[tmp[2]]==1 || cntcnt[tmp[1]]==1)
            {
                if(cntcnt[tmp[2]]==1)
                {

                    for(int i=1; i<=k; i++)
                    {
                        if(cnt[i]==tmp[2])
                        {
                            printf("-%d\n",i);
                            break;
                        }
                    }
                }
                else if(cntcnt[tmp[1]]==1)
                {
                    for(int i=1; i<=k; i++)
                    {
                        if(cnt[i]==tmp[1])
                        {
                            printf("+%d\n",i);
                            break;
                        }
                    }
                }
            }

            else
            {
                printf("*\n");
                continue;
            }




        }
        else
        {
            int flag=0;

            for(int i=2; i<=3; i++)
            {
                if(tmp[i]!=tmp[i-1]+1)
                {
                    printf("*\n");
                    flag=1;
                    break;
                }

            }

            if(flag)
                continue;

            if(cntcnt[tmp[1]]!=1 || cntcnt[tmp[3]]!=1)
            {
                printf("*\n");
                continue;
            }

            int a1,a2;

            for(int i=1; i<=k; i++)
            {
                if(cnt[i]==tmp[1])
                    a1=i;

                if(cnt[i]==tmp[3])
                    a2=i;
            }

            printf("-%d +%d\n",a2,a1);
        }

    }

    return 0;
}


