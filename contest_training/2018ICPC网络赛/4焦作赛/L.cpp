#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
const int Nmax=207;
const int Totmax=1100000+7;
typedef long long ll;
const ll mod=1e9+7LL;
int n,m;
ll times;
int new_id[Nmax];
inline int id(char c)
{
    if(c=='a')
        return 1;
    else if(c=='b')
        return 2;

    return 3;
}
struct Matrix
{
    int n,m;
    ll map[25][25];
    inline void clear() {
        n=m=0;
        memset(map,0,sizeof(map));
    }
    Matrix() {
        n=0,m=0;
    }
    Matrix(int x,int y) {
        n=x;
        m=y;

        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                map[i][j]=0;
    }
    Matrix operator * (const Matrix b) {
        Matrix c(n,b.m);

        if(m==b.n) {
            for(int i=1; i<=c.n; i++)
                for(int k=1; k<=m; k++)
                    for(int j=1; j<=c.m; j++)
                        c.map[i][j]=(c.map[i][j]+(map[i][k]*b.map[k][j])%mod)%mod;

            return c;
        }

        printf("error!!!!!!!!!!!!!!\n");
        exit(0);
        return c;
    }
    void print(int nn,int mm) {
        //printf("n:%d m:%d\n",n,m);
        for(int i=1; i<=nn; i++)
            for(int j=1; j<=mm; j++)
                printf("%d%c",map[i][j],j==mm?'\n':' ');
    }
    void show() {
        printf("n:%d m:%d\n",n,m);

        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                printf("%d%c",map[i][j],j==m?'\n':' ');
    }
};
Matrix base,tmp;

void work()
{
    //printf("yes\n");
    base=tmp;
    Matrix ans(n,n);
    base.n=n,base.m=n;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(i==j)
                ans.map[i][j]=1LL;

    //printf("times:%lld\n",times);
    //ans.show();
    //base.show();
    //ans*ans;
    while(times>0)
    {
        if(times&1LL)
            ans=ans*base;

        base=base*base;
        //ans*ans;
        times>>=1;
    }

    ll res=0LL;

    for(int i=1; i<=n; i++)
        res=(res+ans.map[1][i])%mod;

    res=(res+mod)%mod;
    printf("%lld\n",res);
}
struct Aho
{
    struct State
    {
        int next[3];
        int cnt,fail,num;
    } state_table[Totmax];

    int size;
    queue<int> Q;
    void init() {
        while(Q.size())
            Q.pop();

        for(int j=0; j<3; j++)
            state_table[0].next[j]=-1;

        state_table[0].fail=state_table[0].cnt=state_table[0].num=0;

        for(int j=0; j<3; j++)
            state_table[1].next[j]=-1;

        state_table[1].fail=state_table[1].cnt=state_table[1].num=0;

        size=1;
    }

    void insert(char *s) {
        int n=strlen(s);
        int now=0;

        for(int i=0; i<n; i++) {
            char c=s[i];

            if(state_table[now].next[id(c)-1]==-1) {
                for(int j=0; j<3; j++)
                    state_table[size].next[j]=-1;

                state_table[size].cnt=state_table[size].fail=state_table[size].num=0;
                state_table[now].next[id(c)-1]=size++;
            }

            now=state_table[now].next[id(c)-1];
        }

        state_table[now].cnt=1;
        state_table[now].num=n;
    }

    void build() {
        Q.push(0);
        state_table[0].fail=0;

        while(Q.size()) {
            int now=Q.front();
            Q.pop();

            for(int i=0; i<3; i++) {
                if(now==0) {
                    if(state_table[now].next[i]==-1)
                        state_table[now].next[i]=0;
                    else {
                        state_table[ state_table[now].next[i] ].fail=0;
                        Q.push(state_table[now].next[i]);
                    }
                }
                else {
                    if(state_table[now].next[i]==-1) {
                        state_table[now].next[i]=state_table[ state_table[now].fail ].next[i];
                        //注意如果失配节点是病毒，该节点也应为病毒
                        state_table[now].cnt=state_table[now].cnt||state_table[state_table[now].fail].cnt;
                    }
                    else {
                        state_table[ state_table[now].next[i] ].fail=state_table[ state_table[now].fail ].next[i];
                        Q.push(state_table[now].next[i]);
                    }
                }

            }
        }

        //printf("size:%d\n",size);
    }
    void mk_matrix() {
        n=0;
        base.clear();

        for(int i=0; i<size; i++)
            if(!state_table[i].cnt)
                new_id[i]=++n;

        base.n=base.m=n;

        for(int now=0; now<size; now++) {
            if(state_table[now].cnt)
                continue;

            for(int i=0; i<3; i++) {
                int next_node=state_table[now].next[i];

                if(!state_table[next_node].cnt)
                    base.map[new_id[now]][new_id[next_node] ]=(1LL+base.map[new_id[now]][new_id[next_node]])%mod;
            }
        }
    }
} aho;
char s[107];
inline void init()
{
    aho.init();
    n=m=0;
    memset(new_id,0,sizeof(new_id));

    for(int i=0; i<3; i++)
        s[i]='a';
    s[3]='\0';
    aho.insert(s);

    for(int i=0; i<3; i++)
        s[i]='b';
    s[3]='\0';
    aho.insert(s);

    for(int i=0; i<3; i++)
        s[i]='c';
    s[3]='\0';
    aho.insert(s);

    s[0]='b',s[1]='a',s[2]='b';
    s[3]='\0';
    aho.insert(s);

    s[0]='b',s[1]='c',s[2]='b';
    s[3]='\0';
    aho.insert(s);

    s[0]='a',s[1]='b',s[2]='c';
    s[3]='\0';
    aho.insert(s);

    s[0]='c',s[1]='b',s[2]='a';
    s[3]='\0';
    aho.insert(s);

    aho.build();
    aho.mk_matrix();
    tmp=base;
}
int main()
{
    //freopen("L.in","r",stdin);
    int t;
    scanf("%d",&t);
    init();

    while(t--)
    {
        scanf("%lld",&times);
        work();
    }

    return 0;
}
