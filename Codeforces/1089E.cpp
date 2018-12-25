#include<bits/stdc++.h>
using namespace std;
vector<int> adj[64];
int n;
vector<int>ans;
bool dfs(int x, vector<bool>visited, int len, vector<int>seq)
{
	if(visited[x])
		return 0;
	visited[x]=1;
	seq.push_back(x);
	if(x==63 && len==n)
	{
		ans=seq;
		return true;
	}
	if(len==n && x!=63)
		return 0;
	if(x==63)
		return 0;
	for(auto y:adj[x])
	{
		if(dfs(y, visited, len+1, seq))
			return true;
	}
	return false;
}
int main()
{
	cin>>n;

	for(int i=0; i<64; ++i)
	{
		int x=i/8;
		int y=i%8;
		for(int k=0; k<8; ++k)
		{
			if(k!=y)
			{
				adj[i].push_back(x*8+k);
			}
			if(k!=x)
			{
				adj[i].push_back(k*8+y);
			}
		}
	}
	vector<bool>visited(64,0);
	vector<int>seq;
	dfs(0, visited, 0, seq);
	for(auto x:ans)
	{
		cout<<(char)(x%8+'a')<<x/8+1<<" ";
	}
}