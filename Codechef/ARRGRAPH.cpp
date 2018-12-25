#include<bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

void dfs(bool visited[51], vector<int> adj[51], int x)
{
	if(visited[x])
		return ;
	visited[x]=1;
	for(auto y: adj[x])
	{
		dfs(visited, adj, y);
	}
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int a[n];
		vector<int>adj[n];
		bool visited[n]={};
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		for(int i=0; i<n; ++i)
		{
			for(int j=i+1; j<n; ++j)
			{
				if(__gcd(a[i],a[j])==1)
				{
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
		bool flag=1;	
		dfs(visited, adj, 0);

		for(int i=0; i<n; ++i)
		{
			if(!visited[i])
			{
				flag=0;
				break;
			}
		}

		if(flag)
		{
			cout<<0<<endl;
			for(auto ai:a)
				cout<<ai<<' ';
			cout<<endl;
			continue;
		}

		bool is47=0;
		for(int i=0; i<n; ++i)
		{
			if(a[i]==47)
			{
				is47=1;
				break;
			}
		}

		if(!is47)
		{
			cout<<1<<endl;
			a[0]=47;
			for(auto ai:a)
				cout<<ai<<' ';
			cout<<endl;
			continue;
		}
		a[0]=2;
		cout<<1<<endl;
		for(auto ai:a)
			cout<<ai<<' ';
		cout<<endl;
		continue;

	}
}