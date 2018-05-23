#include <bits/stdc++.h>
using namespace std;
const int Nmax=1e6+7;
typedef long long ll;
char s[Nmax];
char str[Nmax*2+11];
int p[Nmax*2+11],hashh[Nmax*2+11];
int id,maxlen,len,start[Nmax],endd[Nmax];
inline void init()
{
	id=0;
	maxlen=0;
	int n=strlen(s);
	str[0]='$';
	str[1]='#';
	for(int i=0;i<n;i++)
	{
		str[i*2+2]=s[i];
		hashh[i*2+2]=i;
		str[i*2+3]='#';
	}
	str[n*2+2]='&';
	len=n*2+2;
}
inline void get()
{
	for(int i=2;i<=len-2;i++)
	{
		if(id+p[id]>i)
			p[i]=min(p[id*2-i],p[id]+id-i);
		else
			p[i]=1;
		while(str[i-p[i]]==str[i+p[i]])
			p[i]++;
		if(p[i]+i>p[id]+id)
			id=i;
		if(str[i]!='#')
		{
			// printf("%c\n",str[i]);
			// printf("hashh[%d]:%d\n",i,hashh[i]);
			start[hashh[i]]=hashh[i-p[i]+2];
			endd[hashh[i]]=hashh[i+p[i]-2];
		}
	}
}
std::vector<int> ans;
int main()
{
	// freopen("2.in","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		// printf("%s\n",s);
		init();
		get();
		ans.clear();
		int n=strlen(s);
		// for(int i=0;i<n;i++)
		// {
		// 	printf("now:%d start:%d end:%d\n",i,start[i],endd[i]);
		// }
		for(int i=0;i<n;i++)
		{
			int now=i;
			while(start[now]==0)
			{
				if(endd[now]==n-1)
					break;
				if(now==endd[now])
					break;
				now=endd[now];
			}
			if(endd[now]==n-1)
				ans.push_back(i+1);
		}
		int ans_size=(int)ans.size();
		for(int i=0;i<ans_size;i++)
			printf("%d%c",ans[i],i+1==ans_size?'\n':' ');
	}	
    return 0;
}


