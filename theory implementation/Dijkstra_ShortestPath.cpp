#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

int main()
{
	int n, m, x;
	cin>>n>>m;
	vector<pair<int,int>> adj[n+1];
	for(int i=0; i<m; ++i)
	{
		int a, b, w;
		cin>>a>>b>>w;
		adj[a].push_back({b,w});
	}
	cin>>x;
	int distance[n+1];
	priority_queue <pair<int,int>> Q; //(distance,node)
	for (int i = 0; i <= n; ++i)
	{
		distance[i]=INT_MAX;
	}
	distance[x]=0;
	Q.push({0,x});
	bool processed[n+1]={};
	while(Q.size())
	{
		pair<int,int> X=Q.top(); 
		Q.pop();
		if(processed[X.second])
			continue;
		processed[X.second]=1;
		for(auto Y: adj[X.second])
		{
			if(distance[Y.first]>distance[X.second]+Y.second)
			{
				distance[Y.first]=distance[X.second]+Y.second;
				Q.push({-distance[Y.first],Y.first});
			}
		}
	}
	for (int i = 1; i < n+1	; ++i)
	{
		cout<<i<<": "<<distance[i]<<' ';
	}
}