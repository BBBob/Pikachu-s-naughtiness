//#define test
#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
string s[]={
"algorithm",
"bitset", 
"cctype", 
"cerrno", 
"clocale", 
"cmath", 
"complex", 
"cstdio", 
"cstdlib", 
"cstring", 
"ctime", 
"deque", 
"exception", 
"fstream", 
"functional", 
"limits", 
"list", 
"map", 
"iomanip", 
"ios", 
"iosfwd", 
"iostream", 
"istream", 
"ostream", 
"queue", 
"set", 
"sstream", 
"stack", 
"stdexcept", 
"streambuf", 
"string", 
"utility", 
"vector", 
"cwchar", 
"cwctype"
};
map<string,int> mp;
int main()
{
    #ifdef test
    #endif
    for(int i=0;i<35;i++)
        mp[s[i]]=1;
    int t;
    cin>>t;
    while(t--)
    {
        string now;
        cin>>now;
        if(mp[now])
            cout<<"Qian"<<endl;
        else
            cout<<"Kun"<<endl;
    }
    return 0;
}


