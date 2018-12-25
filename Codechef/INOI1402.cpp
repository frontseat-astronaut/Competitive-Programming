#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	int C, F;
	cin>>C>>F;
	int W[C+1][C+1];
	for (int i = 0; i < C+1; ++i)
	{
		for (int j = 0; j < C+1; ++j)
		{
			if(i!=j)
				W[i][j]=INT_MAX;
			else W[i][j]=0;
		}
	}
	for (int i = 0; i < F; ++i)
	{
		int a, b, w;
		cin>>a>>b>>w;
		W[a][b]=w;
		W[b][a]=w;
	}
	int maxm=0;
	for(int k=1; k<=C; ++k)
	{
		for(int i=1; i<=C; ++i)
		{
			for(int j=1; j<=C; ++j)
			{
				W[i][j]=min(W[i][j],W[i][k]+W[k][j]);
			}
		}
	}
	for (int i = 1; i < C+1; ++i)
	{
		for (int j = 1; j < C+1; ++j)
		{
			if(W[i][j]<INT_MAX)
				maxm=max(maxm, W[i][j]);
		}
	}
	cout<<maxm<<endl;
}