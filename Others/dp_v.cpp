#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1;
int n, m;
vector<int>adj[N];

int dp[N]={};

void dfs(int x, int e)
{
	dp[x]=1;
	for(auto y:adj[x])
	{
		if(y!=e)
		{
			dfs(y, x);
			dp[x]=(dp[x]*(dp[y]+1))%m;
		}
	}
}
void dfs2(int x, int e, int preva)
{
    dp[x]=(dp[x]*(preva+1))%m;
    int l=adj[x].size();
    int pref[l], suf[l];
    int pp=1, ps=1;
    for(int i=0; i<l; ++i)
    {
        int y=adj[x][i];
        if(y!=e)
        {
            pp=(pp*(dp[y]+1))%m;
        }
        pref[i]=pp;
    }
    for(int i=l-1; i>=0; --i)
    {
        int y=adj[x][i];
        if(y!=e)
        {
            ps=(ps*(dp[y]+1))%m;
        }
        suf[i]=ps;
    }
    for(int i=0; i<l; ++i)
    {
        int y=adj[x][i];
        if(y!=e)
        {
            int nexta=1;
            if(i!=0)
                nexta=(nexta*pref[i-1])%m;
            if(i!=l-1)
                nexta=(nexta*suf[i+1])%m;
            nexta=(nexta*(preva+1))%m;
            dfs2(y, x, nexta); 
        }
    }
}

int32_t main()
{
	cin>>n>>m;
	for (int i = 0; i < n-1; ++i)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	dfs2(1, 0,(int) 0);
	
	for(int i=1; i<=n; ++i)
		cout<<dp[i]<<'\n';
}