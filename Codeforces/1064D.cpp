#include<bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;
vector<pii>adj[4000005];
bool visited[4000005];
int dist[4000005];
int n,m,r,c,x,y;
int st;
int N=0;
priority_queue<pii>q;
char g[2005][2005];
void dijkstra()
{
	for(int i=0; i<N; ++i)
		dist[i]=INT_MAX;
	dist[st]=0;
	q.push({0,st});
	while(!q.empty())
	{
		pii z=q.top();
		q.pop();
		if(visited[z.s])
			continue;
		visited[z.s]=1;
		for(auto Z :adj[z.s])
		{
			if(dist[Z.s]>dist[z.s]+Z.f)
			{
				dist[Z.s]=dist[z.s]+Z.f;
				q.push({-dist[Z.s],Z.s});
			}
		}
	}
}
int main()
{
	cin>>n>>m>>r>>c>>x>>y;
	r--, c--;
	for (int i = 0; i < n; ++i)
	{
		cin>>g[i];
	}
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<m; ++j, N++)
		{
			if(g[i][j]=='*') continue;
			if(i==r && j==c)
				st=N;
			if(j>0 && g[i][j-1]!='*')
				adj[N].push_back({1,N-1});
			if(j<m-1 && g[i][j+1]!='*')
				adj[N].push_back({0,N+1});
			if(i>0 && g[i-1][j]!='*')
				adj[N].push_back({0,N-m});
			if(i<n-1 && g[i+1][j]!='*')
				adj[N].push_back({0,N+m});
		}
	}
	dijkstra();
	int ans=0;
	for(int i=0; i<N; ++i)
	{
		if(dist[i]<=x && dist[i]+i%m-st%m<=y)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
}	