#include<iostream>
#include<tuple>
#include<vector>
#include<climits>
#define int long long
using namespace std;
//directed graph
int32_t main()
{
	int n, m, x;
	vector<tuple<int,int,int>>e;
	cin>>n>>m;
	for (int i = 0; i < m; ++i)
	{
		int a, b, w;
		cin>>a>>b>>w;
		e.push_back({a,b,w});
	}
	cin>>x;
	int distance[n+1];
	for (int i = 1; i <= n; ++i)
	{
		distance[i]=INT_MAX;
	}
	distance[x]=0;
	for (int i = 0; i < n; ++i)
	{
		for(auto edge:e)
		{
			int a, b, w;
			tie(a,b,w)=edge;
			distance[b]=min(distance[b],distance[a]+w);
		}
	}
	bool negcycle=0;
	for(auto edge:e)
	{
		int a, b, w;
		tie(a,b,w)=edge;
		if(distance[a]+w<distance[b])
		{
			negcycle=1;
			break;
		}
	}
	if(negcycle)
	{
		cout<<"No shortest path"<<endl;
		return 0;
	}
	for(int i=1; i<=n; ++i)
		cout<<i<<": "<<distance[i]<<' ';
}