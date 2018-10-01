#include<iostream>
#include<vector>
using namespace std;

vector<int>adjv[1001];
bool visited[1001];
int govid[1001];
bool adjm[1001][1001];

int dfs(int x, vector<int> &grp, int gov)
{
	if(visited[x])
		return 0;
	visited[x]=1;
	grp.push_back(x);
	govid[x]=gov;
	int cnt=1;
	for(auto y: adjv[x])
		cnt+=dfs(y, grp, gov);
	return cnt;
}


int interconnect(vector<int>grp)
{
	int N=grp.size();
	int ans=0;
	for(int i=0; i<N; ++i)
	{
		for(int j=i+1; j<N; ++j)
		{
			if(adjm[grp[i]][grp[j]]==0)
			{
				ans++;
				adjm[grp[i]][grp[j]]=1;
				adjm[grp[j]][grp[i]]=1;
				adjv[grp[i]].push_back(grp[j]);
				adjv[grp[j]].push_back(grp[i]);
			}
		}
	}
	return ans;
}

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<int>gov;
	for(int i=0; i<k; ++i) 
	{
		int c;
		cin>>c;
		gov.push_back(c);
	}
	for(int i=0; i<m; ++i)
	{
		int u,v;
		cin>>u>>v;
		adjm[u][v]=1, adjm[v][u]=1;
		adjv[u].push_back(v), adjv[v].push_back(u);
	}

	int maxm=0, maxg;
	vector<int>grp;
	int ans=0;
	for(int i=0; i<k; ++i)
	{
		vector <int>tempgrp;
		int cnt=dfs(gov[i], tempgrp, gov[i]);
		if(cnt>=maxm)
		{
			maxm=cnt;
			maxg=i;
			grp=tempgrp;
		}
		ans+=interconnect(tempgrp);
	}
	for(int i=1; i<=n; ++i)
	{
		if(govid[i]==0)
		{
			grp.push_back(i);
		}
	}
	ans+=interconnect(grp);
	cout<<ans<<endl;
	
	
}