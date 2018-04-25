#include <bits/stdc++.h>
using namespace std;
struct man
{
    string name;
    string ans;
    double score;
} male[110];
bool cmp(man x,man y)
{
    if(x.score!=y.score)
        return x.score>y.score;

    return x.name<y.name;
}
int main()
{
    int n,m;
    string x;
    scanf("%d%d",&n,&m);
    cin>>x;

    for(int i=0; i<m; i++)
    {
        double tot=0;
        int cnt=x.size();
        cin>>male[i].name>>male[i].ans;

        for(int j=0; j<cnt; j++)
        {
            if(x[j]==male[i].ans[j])
                tot++;
        }

        male[i].score=tot/(double)cnt;
    }

    sort(male,male+m,cmp);
    male[0].score*=100.0;
    cout<<male[0].name<<endl;
    printf("%.2f\n",male[0].score);
    return 0;
}
