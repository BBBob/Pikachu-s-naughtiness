#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9+7;
const int N = 4e4+7;
int kk;
struct edge{
    int from,to,cap,flow,cost;
    edge(int u,int v,int c,int co){
        from=u;to=v;cap=c,flow=0;cost=co;
    }
};
struct MCMF{
    vector<int> G[N];//存每个点的边
    vector<edge> es;//存所有的边
    int inq[N];//判断是否在队列中
    int d[N];//距离
    int p[N],a[N];//上一条弧与可改进量
    void init(int t){
        for(int i=0;i<=t+10;i++){
            G[i].clear();
        }
        es.clear();
    }
    void addedge(int u,int v,int c,int co){
        es.push_back(edge(u,v,c,co));
        es.push_back(edge(v,u,0,-co));
        int m=es.size();
        G[u].push_back(m-2);
        G[v].push_back(m-1);
    }
    bool SPFA(int s,int t,int &flow,int &cost){
        for(int i=0;i<=t;i++) d[i]=inf;
        memset(inq,0,sizeof(inq));
        d[s]=0;inq[s]=1;p[s]=0;a[s]=inf;
        queue<int> Q;
        Q.push(s);
        while(!Q.empty()){
            int u=Q.front();
            Q.pop();
            inq[u]--;
            for(int i=0;i<G[u].size();i++){
                edge &e=es[G[u][i]];
                if(e.cap>e.flow && d[e.to]>d[u]+e.cost){
                    d[e.to]=d[u]+e.cost;
                    p[e.to]=G[u][i];
                    a[e.to]=min(a[u],e.cap-e.flow);
                    if(!inq[e.to]){
                        inq[e.to]++;
                        Q.push(e.to);
                    }
                }
            }
        }
        if(d[t]==inf) return false;
        flow+=a[t];
        cost+=d[t]*a[t];
        int u=t;
        while(u!=s){
            es[p[u]].flow+=a[t];
            es[p[u]^1].flow-=a[t];
            u=es[p[u]].from;
        }
        return true;
    }
    int Maxflow(int s,int t){
        int flow=0,cost=0;
        kk=0;
        while(SPFA(s,t,flow,cost)) kk++;
        return cost;
    }
};
int main(){
    MCMF ans;
    int t;
    scanf("%d",&t);
    while(t--){
        int m,tot=1;
        map<string,int> mp;
        scanf("%d",&m);
        ans.init(4*m+1);
        for(int i=0;i<m;i++){
            int w;
            string u,v;
            cin>>u>>v;
            scanf("%d",&w);
            if(mp[u]==0){
                mp[u]=tot++;
                if(u=="Shanghai"){
                    ans.addedge(mp[u],mp[u]+2*m,2,0);
                    ans.addedge(mp[u]+2*m,4*m+1,2,0);
                }
                else if(u=="Dalian"||u=="Xian"){
                    ans.addedge(mp[u],mp[u]+2*m,1,0);
                    ans.addedge(0,mp[u],1,0);
                }
                else ans.addedge(mp[u],mp[u]+2*m,1,0);
            }
            if(mp[v]==0){
                mp[v]=tot++;
                if(v=="Shanghai"){
                    ans.addedge(mp[v],mp[v]+2*m,2,0);
                    ans.addedge(mp[v]+2*m,4*m+1,2,0);
                }
                else if(v=="Dalian"||v=="Xian"){
                    ans.addedge(mp[v],mp[v]+2*m,1,0);
                    ans.addedge(0,mp[v],1,0);
                }
                else ans.addedge(mp[v],mp[v]+2*m,1,0);
            }
            ans.addedge(mp[u]+2*m,mp[v],inf,w);
            ans.addedge(mp[v]+2*m,mp[u],inf,w);
        }
        int a=ans.Maxflow(0,4*m+1);
       if(kk==2) printf("%d\n",a);
        else printf("-1\n");
    }
    return 0;
}
