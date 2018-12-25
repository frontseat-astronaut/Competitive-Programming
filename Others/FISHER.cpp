#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int32_t main()
{
	while(1)
	{
		int n, t;
		cin>>n>>t;
		if(!n && !t)
			break;

		pii adj[n+1][n+1];
		for(int i=0; i<n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>adj[i][j].ff;
			}
		}
		for(int i=0; i<n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>adj[i][j].ss;
			}
		}

		//dijkstra
		priority_queue<pii>q[t+1];
		int dist[n][t+1];
		for (int i = 0; i < n; ++i)
		{
			for(int j=0; j<t+1; ++j)
				dist[i][j]=LLONG_MAX;
		}
		bool visited[n][t+1]={};

		dist[0][0]=0;
		q[0].push({0,0});
		for(int ti=0, empty=0; empty<=t; ti=(ti+1)%(t+1))
		{
			if(q[ti].empty())
				empty++;
			else
				empty=0;
			while(!q[ti].empty())
			{
				int x=q[ti].top().ss;
				q[ti].pop();
				if(visited[x][ti])
					continue;
				visited[x][ti]=1;
				for(int y=0; y<n; ++y)
				{
					if(x==y) continue;
					for(int tx=0; tx<=t; ++tx)
					{
						if(dist[x][tx]!=LLONG_MAX)
						{
							int ty=tx+adj[x][y].ff;
							if(ty<=t && dist[x][tx]+adj[x][y].ss<dist[y][ty])
							{
								dist[y][ty]=dist[x][tx]+adj[x][y].ss;
								q[ty].push({-dist[y][ty], y});
							}
						}
					}
				}
			}
		}
		int mint, mind=LLONG_MAX;
		for(int ti=t; ti>=0; --ti)
		{
			if(dist[n-1][ti]<mind)
			{
				mind=dist[n-1][ti];
				mint=ti;
			}
		}
		cout<<mind<<" "<<mint<<"\n";
	}
}