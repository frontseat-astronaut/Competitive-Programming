#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	bool iscomp[5005]={};
	iscomp[0]=1, iscomp[1]=1;
	for(int i=2; i*i<=5001; ++i)
	{
		if(!iscomp[i])
		{
			for(int j=i; j*i<=5001; ++j)
				iscomp[j*i]=1;
		}
	}

	int n;
	cin>>n;
	int a[n+1], pre[n+1]={}, sum=0;
	for (int i = 1; i <= n; ++i)
	{
		cin>>a[i];
		sum+=a[i];
		pre[i]=sum;
	}
	int dp[n+1]={};
	dp[n]=0;
	for(int i=n-1; i>=1; --i)
	{
		for(int j=i; j<=n; ++j)
		{
			if(!iscomp[j-i+1])
			{
				dp[i]=max(dp[i],pre[j]-pre[i-1]);
				if(j<n-1)
					dp[i]=max(dp[i], pre[j]-pre[i-1]+dp[j+2]);
			}
		}
		dp[i]=max(dp[i],dp[i+1]);
	}
	cout<<dp[1]<<endl;
}