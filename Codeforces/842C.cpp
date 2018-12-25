#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1;
vector<int>adj[N];
int maxm1[N], maxm2[N];
int a[N];
int n;
vector<int>div1;
map<int, int>dcnt;

void dfs1(int x, int p)
{
	if(x!=1)
		maxm1[x]=__gcd(maxm1[p], a[x]);
	for(auto y:adj[x])
		if(y!=p)
			dfs1(y, x);
}
void dfs2(int x, int p, int h)
{
	if(x!=1)
	{
		for(auto d:div1)
		{
			if(a[x]%d==0)
			{
				dcnt[d]++;				
			}
			if(dcnt[d]>=h-1)
				maxm2[x]=d;
		}
	}
	else
	{
		maxm2[x]=a[x];
	}
	for(auto y:adj[x])
	{
		if(y!=p)
		{
			dfs2(y, x, h+1);
		}
	}
	for(auto d:div1)
	{
		if(a[x]%d==0)
		{
			dcnt[d]--;				
		}
	}
}

int main()
{
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i+1];
	}
	for (int i = 0; i < n-1; ++i)
	{
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs1(1, 0);
	for(int i=1; i*i<=a[1]; ++i)
		if(a[1]%i==0)
		{
			div1.push_back(i);
			if(i*i!=a[1])
				div1.push_back(a[1]/i);
		}
	sort(div1.begin(), div1.end());
	dfs2(1, 0, 0);
	for(int i=1; i<=n; ++i)
	{
		cout<<max(maxm1[i], maxm2[i])<<" ";
	}
}