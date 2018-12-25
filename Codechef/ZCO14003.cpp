#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int dp[n];
	int price=a[n-1];
	dp[n-1]=a[n-1];
	for(int i=n-2; i>=0; --i)
	{
		if(price<=a[i])
			dp[i]=price+dp[i+1];
		else
		{
			dp[i]=a[i]*(n-i);
			if(dp[i]>dp[i+1])
			{
				price=a[i];
			}
			else
			{
				dp[i]=dp[i+1];
			}
		}
	}
	cout<<dp[0]<<endl;
}