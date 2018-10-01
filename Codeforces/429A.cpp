#include<iostream>
#include<vector>
using namespace std;
int n, u, v;
bool init[100001], goal[100001];
vector<int>adj[100001];
int cnt;
vector<int>picked;
bool visited[100001];

void dfs(int x, int d, vector<bool>change)
{	
	if(visited[x])
		return ;
//	cout<<x<<endl;
	init[x]^=change[d%2];
	if(init[x]!=goal[x])
	{
		change[d%2]=change[d%2]^1;
		init[x]^=1;
		++cnt;
		picked.push_back(x);
	}
	visited[x]=1;
	for (auto y: adj[x])
	{
		dfs(y, d+1, change);
	}
}

int main()
{
	cin>>n;
	for(int i=0; i<n-1; ++i)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1; i<=n; ++i)
	{
		cin>>init[i];
	}
	for(int i=1; i<=n; ++i)
	{
		cin>>goal[i];
	}
	vector<bool> change(2,0);
	dfs(1 , 0, change);
	
	cout<<cnt<<endl;
	for(auto x: picked)
	{
		cout<<x<<endl;
	}
	
}