#include<bits/stdc++.h>
using namespace std;
#define int  long long
const int m=998244353 ;
#define pii pair<int,int>
#define ff first
#define ss second

int32_t main()
{
	int n;
	cin>>n;
	int a[n+1];
	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i];
	}

	map<int, int>mp;
	int jmp[n+1]={};
	vector<pii> sme;
	for (int i = 1; i <= n; ++i)
	{
		if(mp.find(a[i])!=mp.end())
		{
			sme.push_back({mp[a[i]], i});
		}
		else
		{
			mp[a[i]]=i;
		}
	}
	sort(sme.begin(), sme.end());
	int l=-1, r=-1;
	for(auto x:sme)
	{
		if(x.ff>r && x.ss)
		{
			if(l!=-1)
				jmp[l]=r;
			l=x.ff;
			r=x.ss;
		}
		else
		{
			r=max(r,x.ss);
		}
	}
	if(l!=-1)
		jmp[l]=r;

	int dp=1;
	for(int i=1; i<=n; ++i)
	{
		if(i!=1)
			dp=(dp*2)%m;
		if(jmp[i])
		{
			i=jmp[i];
		}
	}
	cout<<dp;
}