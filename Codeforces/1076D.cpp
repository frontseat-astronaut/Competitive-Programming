#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ff  first
#define ss second
#define pb push_back
#define inf LLONG_MAX
using namespace std;

struct edge
{
	int v,w,id;
};

int32_t main()
{
	int n, m, k;
	cin>>n>>m>>k;

	vector<edge>adj[n+1];
	for (int i = 0; i < m; ++i)
	{
		int u, v, w;
		cin>>u>>v>>w;
		adj[u].pb({v,w,i+1});
		adj[v].pb({u,w,i+1});
	}

	//Dijkstra's Algorithm
	priority_queue <pii>q;
	bool vis[n+1]={};
	int dist[n+1]={};
	int cnt=0;
	int edg[n+1];
	vector<int> T;

	for (int i = 0; i < n+1; ++i)
	{
		dist[i]=inf;
	}
	dist[1]=0;
	q.push({0,1});
	while(!q.empty())
	{
		int x=q.top().ss;
		q.pop();
		if(vis[x])
			continue;
		vis[x]=1;
		++cnt;
		T.pb(x);
		if(cnt==k+1)
		{
			break;
		}
		for(auto y: adj[x])
		{
			if(dist[x]+y.w < dist[y.v])
			{
				dist[y.v]=dist[x]+y.w;
				q.push({-dist[y.v],y.v});
				edg[y.v]=y.id;
			}
		}
	}
	cout<<T.size()-1<<endl;
	for(auto x:T)
	{
		if(x!=1)
			cout<<edg[x]<<" ";
	}
	cout<<endl;
}