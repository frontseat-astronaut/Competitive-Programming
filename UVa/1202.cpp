#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second

struct V
{
	int x, y, w;
	bool operator<(const V &b) const
	{
		return w>b.w;
	}
};

int main()
{
	int n,m;
	while(cin>>m>>n)
	{
		if(n==-1)
			break;
		int w[500][500]={};
		for (int i = 0; i < m; ++i)
		{
			int x, y, t;
			bool d;
			cin>>x>>y>>d>>t;
			x<<=1, y<<=1, t<<=1;

			if(d)
			{
				int yi=y+1;
				while(yi<y+t && yi<500 && x<500)
				{
					w[x][yi]=1;
					yi+=2;
				}
			}
			else
			{
				int xi=x+1;
				while(xi<x+t && xi<500 && y<500)
				{
					w[xi][y]=1;
					xi+=2;
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			int x, y;
			bool d;
			cin>>x>>y>>d;
			x<<=1, y<<=1;
			if(x+(!d)<500 && y+d<500)
				w[x+(!d)][y+d]=2;
		}
		vector<V>adj[210][210];
		for(int x=0; x<203; x++)
		{
			for(int y=0; y<203; y++)
			{
				int i=x<<1, j=y<<1;
				if(!w[i+2][j+1])
				{
					adj[x][y].pb({x+1,y,0});
					adj[x+1][y].pb({x,y,0});
				}
				if(w[i+2][j+1]==2)
				{
					adj[x][y].pb({x+1,y,1});
					adj[x+1][y].pb({x,y,1});
				}
				if(!w[i+1][j+2])
				{
					adj[x][y].pb({x,y+1,0});
					adj[x][y+1].pb({x,y,0});
				}
				if(w[i+1][j+2]==2)
				{
					adj[x][y].pb({x,y+1,1});
					adj[x][y+1].pb({x,y,1});
				}
			}
		}
		double f1, f2;
		cin>>f1>>f2;

		if(f1>206)
			f1=206;
		if(f2>206)
			f2=206;
		pii nemo={f1, f2};
		//dijkstra
		int dist[210][210];
		for (int i = 0; i < 205; ++i)
		{
			for (int j = 0; j < 205; ++j)
			{
				dist[i][j]=INT_MAX;
			}
		}
		dist[0][0]=0;
		priority_queue <V> Q;
		Q.push({0,0,0});
		bool processed[210][210]={};
		while(!Q.empty())
		{
			pii x={Q.top().x, Q.top().y};
			Q.pop();
			if(processed[x.f][x.s])
				continue;
			processed[x.f][x.s]=1;
			for(auto y: adj[x.f][x.s])
			{
				if(dist[y.x][y.y]>dist[x.f][x.s]+y.w)
				{
					dist[y.x][y.y]=dist[x.f][x.s]+y.w;
					Q.push({y.x,y.y, dist[y.x][y.y]});
				}
			}
		}
		if(dist[nemo.f][nemo.s]>=INT_MAX)
		{
			cout<<-1<<endl;
		}
		else
			cout<<dist[nemo.f][nemo.s]<<endl;
	}
}