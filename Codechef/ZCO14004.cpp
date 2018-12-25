#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int dp[n+1]={};
	int dp0, dp1, dp2;

	dp[n-1]=a[n-1];
	dp[n-2]=a[n-1]+a[n-2];
	for(int i=n-3; i>=0; --i)
	{
		dp0=0, dp1=0, dp2=0;
		dp0=dp[i+1];
		dp1=dp[i+2]+a[i];
		dp2=a[i]+a[i+1];
		if(i<n-3)
			dp2+=dp[i+3];
		dp[i]=max(dp0, dp1);
		dp[i]=max(dp[i],dp2);
	}
	cout<<dp[0]<<endl;
}	