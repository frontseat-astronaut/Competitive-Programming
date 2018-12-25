#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ff first
#define ss second

const int R=100, C=100;
int r, c, m, n, w, x, y;
int odd, even;

void build(vector<pii>adj[R][C], bool isw[R][C], set<pii>moves)
{
	for(int x=0; x<r; ++x)
	{
		for(int y=0; y<c; ++y)
		{
			if(isw[x][y]) continue;	
			for(auto d:moves)
			{
				if(d.ff+x>=r || d.ff+x<0 || d.ss+y>=c || d.ss+y<0 || isw[d.ff+x][d.ss+y])
					continue;
				adj[x][y].push_back({d.ff+x, d.ss+y});
			}
		}
	}
}

void bfs(vector<pii>adj[R][C])
{
	queue <pii> q;
	bool visited[R][C]={};
	int cnt;
	q.push({0,0});
	visited[0][0]=1;
	while(!q.empty())
	{
		pii s=q.front();
		q.pop();
		cnt=adj[s.ff][s.ss].size();
		if(cnt&1)
			odd++;
		else
			even++;
		for(auto u:adj[s.ff][s.ss])
		{
			if(visited[u.ff][u.ss]) continue;
			visited[u.ff][u.ss]=1;
			q.push(u);
		}
	}
}

int main()
{
	int t, caseno=1;
	cin>>t;
	while(t--)
	{
		cin>>r>>c>>m>>n;

		vector<pii>adj[R][C];
		bool isw[R][C]={};
		set<pii> moves={
			{m,n},
			{m, -n},
			{-m, n},
			{-m, -n},
			{n, m},
			{n,-m},
			{-n,m},
			{-n,-m}
		};

		cin>>w;
		for (int i = 0; i < w; ++i)
		{
			cin>>x>>y;
			isw[x][y]=1;
		}

		build(adj, isw, moves);
		even=0, odd=0;
		bfs(adj);
		cout<<"Case "<<caseno++<<": "<<even<<" "<<odd<<"\n";
	}
}