#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int dp[37][37][37][37];
long long mark[37][37][37][37];
int P,A,C,M;

inline int maxn(int x, int y)
{
    return (x>y?x:y);
}

struct Team
{
    int g;
    int p,a,c,m;
} a[55];
int main()
{
    int N;
    int ansA;
    long long ansB;
    int ansC;
    scanf("%d",&N);

    for(int i = 0; i<N; i++)
        scanf("%d%d%d%d%d",&a[i].p,&a[i].a,&a[i].c,&a[i].m,&a[i].g);

    scanf("%d%d%d%d",&P,&A,&C,&M);
    memset(dp,-1,sizeof(dp));
    dp[0][0][0][0]=0;

    //memset(dp,-1,sizeof(dp));
    for(int i = 0; i < N; i++)
    {
        for(int pi = P; pi >= 0; pi--)
            for(int ai = A; ai >= 0; ai--)
                for(int ci = C; ci >= 0; ci--)
                    for(int mi = M; mi >= 0; mi--)
                    {
                        if((pi-a[i].p>=0 && ai-a[i].a>=0 && ci-a[i].c>=0 && mi-a[i].m>=0) && (dp[pi-a[i].p][ai-a[i].a][ci-a[i].c][mi-a[i].m]!=-1))
                        {
                            //cout << i << " : " <<pi <<' ' <<ai << ' ' <<ci <<' '<<mi<<endl;
                            if(dp[pi][ai][ci][mi] < dp[pi-a[i].p][ai-a[i].a][ci-a[i].c][mi-a[i].m]+a[i].g)//dp[pi][ai][ci][mi] = maxn();
                            {
                                //cout<<"i:"<<i<<endl;
                                dp[pi][ai][ci][mi] = dp[pi-a[i].p][ai-a[i].a][ci-a[i].c][mi-a[i].m]+a[i].g;
                                mark[pi][ai][ci][mi] = (1LL << i) + mark[pi-a[i].p][ai-a[i].a][ci-a[i].c][mi-a[i].m];
                            }
                        }
                    }
    }

    ansA = -1;
    ansB = 0;

    for(int pi = P; pi >= 0; pi--)
        for(int ai = A; ai >= 0; ai--)
            for(int ci = C; ci >= 0; ci--)
                for(int mi = M; mi >= 0; mi--)
                    if(dp[pi][ai][ci][mi]>ansA)
                    {
                        //cout << pi <<' ' <<ai << ' ' <<ci <<' '<<mi<<endl;
                        ansA = dp[pi][ai][ci][mi];
                        ansB = mark[pi][ai][ci][mi];
                    }

    //printf("%d\n",ansA);
    //cout<<ansB<<endl;
    long long t = ansB;
    ansC=0;
    ansA=0;

    while(ansB)
    {
        if(ansB==1)
        {
            ansA++;
            //printf("1\n");
            break;
        }

        if(ansB&1)
        {
            //printf("%d ",ansC);
            ansA++;
        }

        ansC++;
        ansB >>= 1;
    }

    printf("%d\n",ansA);
    ansC=0;
    ansB = t;

    while(ansB)
    {
        if(ansB==1)
        {
            printf("%d\n",ansC);
            break;
        }

        if(ansB&1)
            printf("%d ",ansC);

        ansC++;
        ansB >>= 1;
    }

    return 0;
}