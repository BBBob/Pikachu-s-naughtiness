//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=2e5+7;
typedef long long ll;
struct Node
{
    int len;
    string name;
    string score;
    string cmp;
    int max;
}a[Nmax];
int maxlen;
int n;
bool cmp(const Node &a,const Node &b)
{
    if(a.cmp==b.cmp)
        return a.name<b.name;
    else
        return a.cmp>b.cmp;
}
int main()
{
    #ifdef test
    #endif
    //freopen("2.in","r",stdin);
    ios::sync_with_stdio(false);
    cin>>n;
      
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].name>>a[i].score;    
        a[i].len=a[i].score.length();
        a[i].cmp=a[i].score;
    }
    for(int i=1;i<=n;i++)
    {
        auto it=--a[i].cmp.end();
        while(*it=='0')
        {
            it--;
        }
        a[i].cmp.erase(it+1,a[i].cmp.end());
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
        cout<<a[i].name<<" "<<a[i].score<<endl;
    return 0;
}
