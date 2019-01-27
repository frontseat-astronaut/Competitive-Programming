#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	int n, k;
	cin>>n>>k;

	int a[n];
	bool flag=0;
	map<int,vector<int>>m;
	for(int i=0; i<n; ++i)
	{
		cin>>a[i];
		m[a[i]].push_back(i);
		if(m[a[i]].size()>k)
			flag=1;
	}
	if(flag)
	{
		cout<<"NO";
		exit(0);
	}
	int clr=0;
	int ans[n];
	for(auto x: m)
	{
		for(auto y:x.second)
		{
			ans[y]=clr+1;
			clr=(clr+1)%k;
		}
	}
	cout<<"YES\n";
	for (int i = 0; i < n; ++i)
	{
		cout<<ans[i]<<' ';
	}
}