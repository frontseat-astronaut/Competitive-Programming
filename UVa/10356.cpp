#include<iostream>
#include<vector>
#define inf 1e9
#include<queue>
#define pii pair<int,int>
#define v first
#define w second
using namespace std;

void dijkstra(vector<pii> adj[], int n)
{
	int dist[n][2];
	for(int i=0; i<n; ++i)
	{
		dist[i][0]=inf;
		dist[i][1]=inf;
	}
	dist[0][0]=0;

	priority_queue <pii> Q[2];
	Q[0].push({0,0});

	bool processed[n][2]={};
	while(!Q[0].empty() || !Q[1].empty())
	{
		for(int i=0; i<2; ++i)
		{
			if(!Q[i].empty())
			{
				int x=Q[i].top().w;
				Q[i].pop();
				if(processed[x][i])
				{
					continue;
				}
				processed[x][i]=1;
				for(auto y:adj[x])
				{
					if(dist[y.v][0]>dist[x][1]+y.w)
					{
						dist[y.v][0]=dist[x][1]+y.w;
						Q[0].push({-dist[y.v][0], y.v});
					}
					if(dist[y.v][1]>dist[x][0]+y.w)
					{
						dist[y.v][1]=dist[x][0]+y.w;
						Q[1].push({-dist[y.v][1], y.v});
					}
				}
			}
		}
		
	}
	if(dist[n-1][0]>=inf)
		cout<<"?"<<endl;
	else
		cout<<dist[n-1][0]<<endl;
}

int main()
{
	int n, m;
	int scnt=1;
	while(cin>>n>>m)
	{
		vector<pii>adj[n];
		for (int i = 0; i < m; ++i)
		{
			int u, v, w;
			cin>>u>>v>>w;

			adj[u].push_back({v,w});
			adj[v].push_back({u,w});
		}
		cout<<"Set #"<<scnt++<<endl;
		dijkstra(adj, n);
	}
	return 0;	
}