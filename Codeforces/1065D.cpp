#include<bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define int long long
using namespace std;
pii addp(pii a, pii b)
{
	return {a.f+b.f, a.s+b.s};
}
int n,n2;
int b[11][11];
pii W[303][303];
pii dp[3][101],minm;
int32_t main()
{
	cin>>n;
	n2=n*n;
	for (int i = 0; i <= 3*n2; ++i)
	{
		for (int j = 0; j <= 3*n2; ++j)
		{
			W[i][j]={INT_MAX,INT_MAX};
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>b[i][j];
		}
	}
	pii kght[]={{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1}};
	for(int i=0; i<n; ++i)
		for (int j = 0; j < n; ++j)
		{
			for(pii d:kght)
			{
				if(i+d.f>=0 && i+d.f<n && j+d.s>=0 && j+d.s<n)
				{
					W[ b[i][j] ][ b[i+d.f][j+d.s] ]={1,0};
				}
			}
			for (int l = 0; l < n; ++l)
			{
				for (int m = 0; m < n; ++m)
				{
					if(i+j==l+m || i-j==l-m)
						W[b[i][j]+n2][b[l][m]+n2]={1,0};
					if(i==l ||j==m)
						W[b[i][j]+2*n2][b[l][m]+2*n2]={1,0};
				}
			}
			W[b[i][j] ][b[i][j] ]=W[b[i][j] +n2][b[i][j] +n2]=W[b[i][j] +2*n2][b[i][j] +2*n2]={0,0};
			for(int p=0; p<3; ++p)
			{
				W[b[i][j]+p*n2][b[i][j]+((p+1)%3)*n2]={1,1};
				W[b[i][j]+((p+1)%3)*n2][b[i][j]+p*n2]={1,1};
			}
		}
	for(int k=1; k<=3*n*n; ++k)
	{
		for(int i=1; i<=3*n*n; ++i)
		{
			for (int j = 1; j < 3*n*n+1; ++j)
			{
				W[i][j]=min(W[i][j],addp(W[i][k],W[k][j]));
			}
		}
	}
	/*
	for(int i=1; i<=3*n*n; ++i)
	{
		for (int j = 1; j < 3*n*n+1; ++j)
		{
			if(W[i][j].f>=INT_MAX)
				cout<<0<<' ';
			else
				cout<<W[i][j].f<<' ';
		}
		cout<<'\n';
	}*/
	
	dp[0][n2]=dp[1][n2]=dp[2][n2]={0,0};
	for(int i=n2-1; i>=1; --i)
	{
		for(int p=0; p<3; ++p)
		{
			dp[p][i]=addp(dp[p][i+1],W[i+n2*p][i+1+n2*p]);
			dp[p][i]=min(dp[p][i],addp(dp[(p+1)%3][i+1],W[i+n2*p][i+1+((p+1)%3)*n2]));
			dp[p][i]=min(dp[p][i],addp(dp[(p+2)%3][i+1],W[i+n2*p][i+1+((p+2)%3)*n2]));
				
		}
	}
	minm=dp[0][1];
	minm=min(minm,dp[1][1]);
	minm=min(minm,dp[2][1]);
	cout<<minm.f<<' '<<minm.s<<endl;

}