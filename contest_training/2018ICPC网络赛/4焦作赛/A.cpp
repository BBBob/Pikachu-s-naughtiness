//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
string a,b;
string now;
int main()
{
    #ifdef test
    #endif
    int t;
    cin>>t;
    a="jessie";
    while(t--)
    {
        cin>>now;
        int n=now.length();
        for(int i=0;i<n;i++)
            if(now[i]>='A' && now[i]<= 'Z')
                now[i]=now[i]-'A'+'a';
        if(now==a)
            cout<<"Good guy!"<<endl;
        else
            cout<<"Dare you say that again?"<<endl;
    }
    return 0;
}


