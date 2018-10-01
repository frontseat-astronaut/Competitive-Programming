#include<iostream>
#include<vector>
using namespace std;
bool adjm[101][101];
int n, m,s;
vector<int>seq;
int DFS(int s, int dest, int prev, int len)
{
	len++;
	if(len>=200)
		return -1;
	if(s==dest)
		return 1;
	for(int i=0; i<n; ++i)
	{
		if(i==prev) continue;
		if(adjm[s][i])
		{
			int dfs=DFS(i,dest, s, len);
			if(dfs==1)
			{
				seq.push_back(i);
				return true;
			}
			else if (dfs ==-1)
				return -1;
		}
	}
	return false;
}
int main()
{
	int N,caseno=1;
	cin>>N;
	while(N--)
	{
		cin>>n>>m>>s;
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
				adjm[i][j]=0;
		}
		for(int i=0; i<m; ++i)
		{
			int u,v;
			cin>>u>>v;
			adjm[u][v]=1;
			adjm[v][u]=1;
		}
		cout<<"Case #"<<caseno++<<":"<<endl;
		for(int i=0; i<n; ++i)
		{
			seq.clear();
			int dfs=DFS(s,i,-1,0);
			if(dfs==1)
			{
				seq.push_back(s);
				int L=seq.size();
				cout<<seq[L-1];
				for(int j=L-2; j>=0; --j)
					cout<<" "<<seq[j];
				cout<<endl;
			}
			else
				cout<<"No drive."<<endl;
		}
		cout<<endl;
	}
}