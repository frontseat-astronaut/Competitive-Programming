#include<map>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, m;
		cin>>n>>m;
		bool g[n+1][m+1];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin>>g[i][j];
			}
		}
		map<pair<int,int>, bool>M;
		bool flag=1;
		for (int i = 0; i < m; ++i)
		{
			int cnt=0;
			vector<int>v;
			int k=0;
			for (int j = 0; j < n; ++j)
			{
				if(g[j][i])
				{
					v.push_back(j);
					cnt++;
				}
			}
			if(cnt!=2)
			{
				flag=0;
				break;
			}
			if(M[{v[0], v[1]}])
			{
				flag=0;
				break;
			}
			M[{v[0],v[1]}]=1;
		}
		if(flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;

	}
}