#include<bits/stdc++.h>
#define int long long
using namespace std;
int m=998244353;
int n, e;
int dfs(int x, bool visited[], vector<int>adj[], int par[])
{
	visited[x]=1;
	int tmp=1;
	for(auto y:adj[x])
	{
		if(visited[y])
		{
			if(par[y]==par[x])
				return 0;
		}
		else
		{
			par[y]=(par[x])%2+1;
			tmp=(tmp*((1<<(par[y]-1))*dfs(y, visited, adj, par))%m)%m;
		}
	}
	return tmp;
}
int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>e;
		vector<int>adj[n+1];
		for (int i = 0; i < e; ++i)
		{
			int u, v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		bool visited1[n+1]={}, visited2[n+1]={};
		int par1[n+1]={}, par2[n+1]={};
		int ans=1, tmp=0;
		for(int i=1; i<=n; ++i)
		{
			if(visited1[i])
				continue;
			par1[i]=2;
			par2[i]=1;
			tmp=(dfs(i, visited1, adj, par1)*2)%m;
			tmp=(tmp+dfs(i, visited2, adj, par2))%m;
			ans=(ans*tmp)%m;
		}
		cout<<ans<<"\n";
	}
}