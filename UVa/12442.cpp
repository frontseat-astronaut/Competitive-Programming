#include<bits/stdc++.h>
using namespace std;
map<int,int>seq;
int dfs(int x, vector<int>adj[], bool visited[], int pth[], int len, bool &cyc, int &start)
{
	if(visited[x])
	{
		if(!pth[x])
		{
			cyc=1;
			start=seq[x];
			return len - seq[x]+1;
		}
		else
		{
			cyc=0;
			return pth[x]+1;
		}
	}
	visited[x]=1;
	seq[x]=len+1;
	pth[x]=dfs(adj[x][0], adj, visited, pth, len+1, cyc, start);
	// cout<<pth[x]<<" ";
	if(cyc && len+1==start)
		cyc=0;
	if(cyc)
	{
		return pth[x];
	}
	else
		return pth[x]+1;
}
int32_t main()
{
	int t;
	int caseno=1;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		vector<int>adj[n+1];
		bool visited[n+1]={};
		int maxm=0, maxi=1, tmp;
		bool cyc;
		int pth[n+1]={};
		
		for(int i=0; i<n; ++i)
		{
			int u, v;
			cin>>u>>v;
			adj[u].push_back(v);
		}
		
		for(int i=1; i<=n; ++i)
		{
			if(visited[i]) 
				continue;
			seq.clear();
			int start;
			dfs(i, adj, visited, pth, 0, cyc, start);
		}
		for(int i=1; i<=n; ++i)
		{
			if(pth[i]>maxm)
			{
				maxm=pth[i];
				maxi=i;
			}
			// cout<<pth[i]<<' ';
		}

		cout<<"Case "<<caseno++<<": "<<maxi<<endl;
		// cout<<maxm<<endl;
	}
}