#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,ans;
    scanf("%d%d",&n,&m);
    map<int,int> mp1;
    map<int,int> mp2;
    if(n%2==0){
        ans=n*2;
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if(!mp1.count(x)){
                ans--;
                mp1[x]++;
            }
            if(!mp2.count(y)){
                ans--;
                mp2[y]++;
            }
        }
        if(ans<0) ans=0;
    }
    else{
        ans=n*2-1;
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if(!mp1.count(x)){
                ans--;
                mp1[x]++;
            }
            if(!mp2.count(y)){
                ans--;
                mp2[y]++;
            }
        }
        if(mp1[n/2+1]&&mp2[n/2+1]) ans++;
        if(ans<0) ans=0;
    }
    cout<<ans<<endl;
    return 0;
}
