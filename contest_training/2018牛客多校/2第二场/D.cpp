#include <bits/stdc++.h>
using namespace std;
const int M = 1e5+7;
typedef long long ll;
int main(){
    int t,a[M];
    int n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int s,ans=0,pre;
        ll tot=0;
        for(int i=1;i<=n;i++){
            if(i==1){
                s=1,pre=a[i];
            }
            else{
                if(s==1){
                    if(a[i]<=pre){
                        pre=a[i];
                    }
                    else if(a[i]>pre){
                        while(a[i]<=a[i+1]&&i<n){
                            i++;
                        }
                        tot+=(a[i]-pre);ans+=2;s=0;
                    }
                }
                else if(s==0){
                    s=1;pre=a[i];
                }
            }
        }
        cout<<tot<<" "<<ans<<endl;
    }
    return 0;
}
