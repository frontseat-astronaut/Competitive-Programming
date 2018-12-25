#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int n, m, ans;
void bfs(pii s, int g[101][101], int visited[101][101])
{
	int f=g[x.ff][x.ss], w=g[x.ff][x.ss];
	queue <pii> q;
	q.insert(s);
	while(!q.empty())
	{
		
	}
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
		cin>>n>>m;
		int g[101][101]={};
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin>>g[i][j];
			}
		}
		ans=0;

	}
}