#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adj[N];
int clr[N]={};
set<int>cs[2];
bool dfs(int x, int c)
{
	if(clr[x])
	{
		if(c!=clr[x])
			return 0;
		else
			return 1;
	}
	clr[x]=c;
	cs[c-1].insert(x);
	for(int y: adj[x])
	{
		if(!dfs(y, ((c-1)^1) +1))
			return 0;
	}
	return 1;
}

int32_t main()
{
    int n, m;
    cin>>n>>m;
    for (int i = 0; i < m; ++i)
    {
    	int u, v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);    	
    }
    bool flag=1;
    for(int i=1; i<=n; ++i)
    {
    	if(!clr[i])
    	{
    		flag=dfs(i, 1);
    		if(!flag)
    		{
    			cout<<-1;
    			break;
    		}
    	}
    }
    if(flag)
    {
    	for(int i=0; i<2; ++i)
    	{
    		cout<<cs[i].size()<<"\n";
    		for(auto y: cs[i])
    			cout<<y<<" ";
    		cout<<"\n";
    	}
    }
}