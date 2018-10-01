#include<iostream>
#include<set>
using namespace std;

int main()
{
	int N;
	cin>>N;
	int caseno=1;
	while(N--)
	{
		int n, m;
		cin>>n>>m;
		bool adjm[n+1][n+1]={};
		set<int>p1[n+1];
		bool ans[n+1]={};
 
		for(int i=0; i<m; ++i)
		{
			int u,v;
			cin>>u>>v;
			adjm[u][v]=1;
			adjm[v][u]=1;

			p1[u].insert(v);
			p1[v].insert(u);
		}

		int e=m, p2e=0;
		while(2*e>m)
		{
			int maxm=0, maxi;
			for(int i=1; i<n+1; ++i)
			{
				if(maxm<=(p1[i].size()))
				{
					maxm=p1[i].size();
					maxi=i;
				}
			}
			e-=maxm;

			for(auto x:p1[maxi])
			{
				p1[x].erase(maxi);
			}
			p1[maxi].clear();
			ans[maxi]=1;

			for(int i=1; i<=n; ++i)
			{
				if(!ans[i]) continue;
				if(adjm[maxi][i])
					e++;
			}
			p2e++;
		}
		cout<<"Case #"<<caseno++<<": "<<p2e<<endl;
		for(int i=1; i<=n; ++i)
			if(ans[i]) cout<<i<<" ";
		cout<<endl;
	}
}