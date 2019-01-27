#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	int n;
	cin>>n;
	double p[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>p[i];
	}
	double dp[n][n+1]={};
	dp[0][0]=1-p[0];
	dp[0][1]=p[0];
	for(int i=1; i<n; ++i)
	{
		for(int j=0; j<=i+1; ++j)
		{
			dp[i][j]=dp[i-1][j-1]*p[i] + dp[i-1][j]*(1.0-p[i]);
		}
	}
	double ans=0.0;
	for(int i=n; 2*i>n; --i)
		ans+=dp[n-1][i];
	printf("%.9lf", ans);
}