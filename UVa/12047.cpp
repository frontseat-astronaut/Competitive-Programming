#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second

int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n, m, s, t, p;
		cin>>n>>m>>s>>t>>p;
		vector<pii>adj[n+1], adjr[n+1];
		vector<tuple<int,int,int>>e;
		for (int i = 0; i < m; ++i)
		{
			int u, v, c;
			cin>>u>>v>>c;
			adj[u].pb({c,v});
			adjr[v].pb({c,u});
			e.pb({c, u, v});
		}
		//dijkstra
		int dists[n+1]={};
		bool pros[n+1]={};
		for (int i = 0; i < n+1; ++i)
		{
			dists[i]=INT_MAX;
		}
		dists[s]=0;
		priority_queue<pii>q;
		q.push({0,s});
		while(!q.empty())
		{
			int x=q.top().s;
			q.pop();
			if(pros[x])
				continue;
			pros[x]=1;
			for(auto y:adj[x])
			{
				if(dists[y.s]>dists[x]+y.f)
				{
					dists[y.s]=dists[x]+y.f;
					q.push({-dists[y.s], y.s});
				}
			}
		}

		int distt[n+1]={};
		bool prot[n+1]={};
		for (int i = 0; i < n+1; ++i)
		{
			distt[i]=INT_MAX;
		}
		distt[t]=0;
		q.push({0,t});
		while(!q.empty())
		{
			int x=q.top().s;
			q.pop();
			if(prot[x])
				continue;
			prot[x]=1;
			for(auto y:adjr[x])
			{
				if(distt[y.s]>distt[x]+y.f)
				{
					distt[y.s]=distt[x]+y.f;
					q.push({-distt[y.s], y.s});
				}
			}
		}

		int maxm=-1;
		for(auto edge:e)
		{
			int u,v,w;
			tie(w,u,v)=edge;
			if(dists[u]+w+distt[v]<=p)
			{
				maxm=max(maxm, w);
			}
		}
		cout<<maxm<<endl;

	}
}