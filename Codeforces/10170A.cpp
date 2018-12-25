#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define f first
#define s second

struct str
{
	int dist;
	string num;
	int ds,rem;

	bool operator<(const str &b) const
	{
		if(dist==b.dist)
			return lexicographical_compare(b.num.begin(), b.num.end(), num.begin(), num.end());
		return dist>b.dist;
	
}};

int main()
{
	int d, s;
	cin>>d>>s;

	priority_queue<str>q;
	pair<int,string> dist[501][5001];
	bool visited[501][5001]={};
	int ds, r;


	for(int i=0; i<501; ++i)
	{
		for(int j=0; j<5001; ++j)
		{
			dist[i][j]={INT_MAX, "-1"};
		}
	}
	dist[0][0]={0,"0"};

	q.push({0,"0",0, 0});

	while(!q.empty())
	{
		pii x={q.top().ds, q.top().rem};
		q.pop();
		if(visited[x.f][x.s])
			continue;
		visited[x.f][x.s]=1;
		if(x.f==s && x.s==0)
		{
			break;
		}
		for(int i=0; i<=9; ++i)
		{
			ds=x.f+i, r=(x.s*10+i)%d;
			if(dist[ds][r].f>dist[x.f][x.s].f+1)
			{
				dist[ds][r].f=dist[x.f][x.s].f+1;
				dist[ds][r].s=dist[x.f][x.s].s;
				dist[ds][r].s.pb(i+'0');
			}
		}
	}
	cout<<dist[s][0].s<<endl;

}