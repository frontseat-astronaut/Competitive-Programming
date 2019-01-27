#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+1;
int a[N];
int n;
vector<int>adj[N];
int out[N], dp[N], sma[N];
int tsm;

void dfs1(int x, int prev)
{
	for(auto y:adj[x])
		if(y!=prev) dfs1(y, x);
	sma[x]=a[x];
	for(auto y:adj[x])
	{
		if(y!=prev)
		{
			out[x]+=out[y]+sma[y];
			sma[x]+=sma[y];
		}
	}
}
void dfs2(int x, int prev)
{
	dp[x]=out[x];
	if(x!=1)
		dp[x]+=dp[prev]-(out[x]+sma[x])+tsm-sma[x];
	for (auto y:adj[x])
	{
		if(y!=prev)
			dfs2(y,x);
	}
}

int32_t main()
{
	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i];
		tsm+=a[i];
	}
	for (int i = 0; i < n-1; ++i)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1, 0);

	int maxm=0;
	for(int x:dp)
		maxm=max(maxm, x);
	// cout<<dp[2]<<"\n";
	cout<<maxm;
}