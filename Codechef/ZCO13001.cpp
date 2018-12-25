#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	int n;
	cin>>n;
	int sum=0;
	int a[n];
	for(int i=0; i<n; ++i)
		cin>>a[i];
	sort(a, a+n);
	int dp[n+1]={};
	dp[0]=0;
	for(int i=1; i<n; ++i)
	{
		dp[i]=i*(a[i]-a[i-1])+dp[i-1];
		sum+=dp[i];
	}
	cout<<sum<<endl;
}