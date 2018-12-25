#include<bits/stdc++.h>
using namespace std;
const int N=101;
vector<int>adj[N];
int diam=0;
int dist[2][N];
int maxm[2], maxmv[2];

int dfs1(int x, int e)
{
	int toleaf1=0, toleaf2=0, tmp;
	for(auto y:adj[x])
	{
		if(y==e) continue;
		tmp=dfs1(y, x)+1;
		if(tmp>toleaf1)
		{
			toleaf2=toleaf1;
			toleaf1=tmp;
		}
		else if(tmp>toleaf2)
		{
			toleaf2=tmp;
		}
	}
	diam=max(diam, toleaf1+toleaf2);
	return toleaf1;
}

void dfs2(int x, int e, int d, bool s)
{
	dist[s][x]=d;
	for(auto y:adj[x])
	{
		if(y==e) continue;
		dfs2(y, x, d+1, s);
	}
}

int main()
{
	int n, u, v;
	cin>>n;
	for (int i = 0; i < n-1; ++i)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//algorithm1
	dfs1(1, 0);
	cout<<diam<<endl;

	//algorithm2
	dfs2(1, 0, 0, 0);
	for(int i=1; i<=n; ++i)
	{
		if(maxm[0]<dist[0][i])
		{
			maxm[0]=dist[0][i];
			maxmv[0]=i;
		}
	}
	dfs2(maxmv[0], 0, 0, 1);
	for(int i=1; i<=n; ++i)
	{
		maxm[1]=max(maxm[1], dist[1][i]);
	}
	cout<<maxm[1]<<endl;
}