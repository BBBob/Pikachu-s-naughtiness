//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=250007;
const int Cmax=26;
typedef long long ll;
int n,a,b;
ll ans;
string s;
struct SuffixAutomaton
{
    int cnt,root,last;
    int next[Nmax*2],Max[Nmax*2],end_pos[Nmax*2],right[Nmax*2];
    int child[Nmax*2][Cmax];
    SuffixAutomaton() {
        cnt=0;
        root=last=newnode(0);
    }
    inline void clear() {
        ans=0LL;
        cnt=0;
        memset(next,0,sizeof(next));
        memset(Max,0,sizeof(Max));
        memset(end_pos,0,sizeof(end_pos));
        memset(right,0,sizeof(right));
        memset(child,0,sizeof(child));
        root=last=newnode(0);
    }
    int newnode(int val) {
        cnt++;
        next[cnt]=end_pos[cnt]=0;
        Max[cnt]=val;
        memset(child[cnt],0,sizeof(child[cnt]));
        return cnt;
    }
    void insert(int data,int k) {
        int p=last,u=newnode(Max[last]+1);
        last=u;

        for(; p&&!child[p][data]; p=next[p])
            child[p][data]=u;

        if(!p)
            next[u]=root;
        else {
            int old=child[p][data];

            if(Max[old]==Max[p]+1)
                next[u]=old;
            else {
                int New=newnode(Max[p]+1);
                copy(child[old],child[old]+Cmax,child[New]);
                right[New]=right[old];
                next[New]=next[old];
                next[u]=next[old]=New;

                for(; child[p][data]==old; p=next[p])
                    child[p][data]=New;
            }
        }

        p=last;

        while(p&&right[p]<k) {
            right[p]++;

            if(right[p]==k)
                ans+=(ll)Max[p]-Max[next[p]];

            p=next[p];
        }
    }
    void build(string s,int k) {
        int n=(int)s.length();
        ans=0LL;

        for(int i=0; i<n; i++)
            insert(s[i]-'A',k);
    }
} sam;
int main()
{
    //freopen("H.in","r",stdin);
    ios::sync_with_stdio(false);

    while(cin>>s>>a>>b)
    {
        sam.clear();
        sam.build(s,a);
        ll ans1=ans;
        sam.clear();
        sam.build(s,b+1);
        ll ans2=ans;
        cout<<ans1-ans2<<endl;
    }

    return 0;
}
