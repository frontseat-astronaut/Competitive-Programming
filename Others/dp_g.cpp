#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e5+1, M=1e5+1;
int dp[N];
vector<int>adj[N];
bool visited[N];
int maxm=0, n, m;
void dfs(int x)
{
	if(visited[x])
		return;
	visited[x]=1;
	for(auto y:adj[x])
	{
		dfs(y);
		dp[x]=max(dp[x], dp[y]);
	}
	maxm=max(maxm, dp[x]);
}

int32_t main()
{
	cin>>n>>m;
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	for(int i=1; i<=n; ++i)
	{
		dfs(i);
	}
	cout<<maxm;
}
