#include<bits/stdc++.h>
using namespace std;
#define int long long
int m=1000000007;
int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int dp[n+1]={};
	dp[0]=1;
	for(int i=0; i<n; ++i)
	{
		vector<int>fact;
		int ddp[n+1]={};
		for(int j=1, k; j*j<=a[i] && j<=i+1; ++j)
		{
			if(a[i]%j==0)
			{
				if(j<=i+1)
				{
					fact.push_back(j);
				}
				k=a[i]/j;
				if(k<=i+1 && k!=j)
				{
					fact.push_back(k);
				}
			}
		}
		for(auto f:fact)
			ddp[f]=dp[f-1];
		for(auto f:fact)
			dp[f]=(ddp[f]+dp[f])%m;
	}
	int ans=0;
	for(int i=1; i<=n; ++i)
		ans=(ans+dp[i])%m;
	cout<<ans<<endl;
}