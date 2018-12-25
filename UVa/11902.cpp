#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n;

void dfs(int x, bool v[], vector<int>adj[])
{
	if(v[x])
		return;
	v[x]=1;
	for(auto y:adj[x])
		dfs(y, v, adj);
}

int main()
{
	int t, caseno=1;
	cin>>t;
	while(t--)
	{
		cout<<"Case "<<caseno++<<":\n";
		cin>>n;

		vector<int>adj[N];
		bool c;

		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				cin>>c;
				if(c)
				{
					adj[i].push_back(j);
				}
			}
		}

		bool p[N][N];

		bool v[N]={};
		dfs(0, v, adj);

		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				bool v1[N]={};
				v1[i]=1;
				dfs(0, v1, adj);
				v1[i]=0;
				p[i][j]=!v1[j]&(v[j]);
			}
		}
		for(int i=0; i<n; ++i)
		{
			cout<<'+';
			for(int j=0; j<2*n-1; ++j)
				cout<<'-';
			cout<<"+\n|";
			for(int j=0; j<n; ++j)
				cout<<((p[i][j])?'Y':'N')<<'|';
			cout<<"\n";
		}
		cout<<'+';
		for(int j=0; j<2*n-1; ++j)
			cout<<'-';
		cout<<"+\n";
	}
}