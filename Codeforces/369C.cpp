#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int>ans;
bool visited[100001]={0};
vector<pair<int,int>>adj[100001];

int dfs(vector<pair<int,int>>adj[], int x)
{
	if(visited[x])
	{
		return -1;
	}
	visited[x]=1;

	if(adj[x].size()==1 && x!=1)
	{
		if(adj[x][0].second==2)
		{
			ans.push_back(x);
			return 1;
		}
		else
		{
			return 0;
		}
	}

	bool leaf=false, own=false ;
	for(auto next: adj[x])
	{
		int DFS=dfs(adj,next.first);
		if(DFS==1)
		{
			leaf=true;
		}
		else if(DFS==-1)
		{
			if(next.second==2)
			{
				own=true;
			}
		}
	}
	if(leaf==true)
	{
		return true;
	}
	else if(own==true)
	{
		ans.push_back(x);
		return true;
	}
	return false;
}

int main()
{
	cin>>n;

	for(int i=0; i<n-1; ++i)
	{
		int a, b, t;
		cin>>a>>b>>t;

		adj[a].push_back({b,t});
		adj[b].push_back({a,t});
	}

	dfs(adj,1);

	cout<<ans.size()<<endl;
	for(auto x: ans)
	{
		if(x==1) continue;
		cout<<x<<" ";
	}
	cout<<endl;

}