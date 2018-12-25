#include<bits/stdc++.h>
#define m 1000000007
#define int long long
using namespace std;
int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n, num;
		cin>>n;
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		vector<int>dp(750005, 0);
		int ans=0;
		for(int i=n-1; i>=0; --i)
		{
			dp[a[i]]=(dp[a[i]]+1)%m;
			for(int j=2*a[i]; j<=a[n-1]; j+=a[i])
			{
				dp[a[i]]=(dp[j]+dp[a[i]])%m;
			}
			ans=(ans+dp[a[i]])%m;
		}
		printf("%ld\n", ans);
	}
}