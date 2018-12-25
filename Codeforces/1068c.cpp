#include<bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;

	vector<int>adj[n+1];
	vector<pii> p[n+1];
	int rcnt[n+1]={};
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin>>u>>v;
		adj[u].pb(v);
	}
	int x=1, y=1, dir, cnt;
	pii newr;
	for (int i = 1; i < n+1; ++i)
	{
		cnt=rcnt[i];
		for(int j=0; j<cnt; ++j)
		{
			if(p[i][j].f>=p[i][j].s)
			{
				p[i].pb({x,p[i][j].s});
				rcnt[i]++;
				break;
			}
			else
			{
				p[i].pb({p[i][j].f,y});
				rcnt[i]++;
				break;
			}
		}
		rcnt[i]++;
		p[i].pb({x, y});

		dir=0;
		for(auto c:adj[i])
		{
			if(dir==2)
			{
				x+=2;
				y+=2;
				dir=0;
				cnt=rcnt[i];
				for(int j=0; j<cnt; ++j)
				{
					if(p[i][j].f>=p[i][j].s)
					{
						p[i].pb({x,p[i][j].s});
						rcnt[i]++;
						break;
					}
					else
					{
						p[i].pb({p[i][j].f,y});
						rcnt[i]++;
						break;
					}
				}
				rcnt[i]++;
				p[i].pb({x, y});
			}
			newr={x+dir, y+(!dir)};
			cnt=rcnt[c];
			for(int j=0; j<cnt; ++j)
			{
				if(p[c][j].f>=p[c][j].s)
				{
					p[c].pb({newr.f,p[c][j].s});
					rcnt[c]++;
					break;
				}
				else
				{
					p[c].pb({p[c][j].f,newr.s});
					rcnt[c]++;
					break;
				}
			}
			p[c].pb(newr);
			rcnt[c]++;
			dir++;
		}
		x+=2;
		y+=2;
	}
	for (int i = 1; i < n+1; ++i)
	{
		cout<<rcnt[i]<<endl;
		for(auto r:p[i])
		{
			cout<<r.f<<" "<<r.s<<endl;
		}
	}
}