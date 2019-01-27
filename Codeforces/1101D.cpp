#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+1;
int n, maxm, m1, m2;
int ii, ij;
int a[N];
vector<int>adj[N];
int in1[N][7], in2[N][7];
vector<int>pr[N];

void dfs(int x, int prev)
{
	for(auto y: adj[x])
	{
		if(y==prev) continue;
		dfs(y, x);
		ii=0;
		for(auto pi: pr[x])
		{
			ij=0;
			for(auto pj: pr[y])
			{
				if(pi==pj)
				{
					if(in1[x][ii]<in1[y][ij])
					{
						in2[x][ii]=in1[x][ii];
						in1[x][ii]=in1[y][ij];
					}
					else
					{
						in2[x][ii]=max(in2[x][ii], in1[y][ij]);
					}
					break;
				}
				ij++;
			}
			ii++;
		}
	}
	ii=0;
	for(auto pi:pr[x])
	{
		maxm=max(maxm, in1[x][ii]+in2[x][ii]+1);
		in1[x][ii]++;
		ii++;
	}
}

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i];
		int ai=a[i];
		for(int j=2; j*j<=ai; ++j)
		{
			if(ai%j==0)
			{
				pr[i].push_back(j);
				in1[i][ pr[i].size()-1 ]=0;
				in2[i][pr[i].size()-1]=0;
				while(ai%j==0)
					ai/=j;
			}
		}
		if(ai>1)
		{
			pr[i].push_back(ai);
			in2[i][pr[i].size()-1]=0;
			in1[i][pr[i].size()-1]=0;
		}
	}
	for (int i = 0; i < n-1; ++i)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	cout<<maxm;
}