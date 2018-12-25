#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, k, x;
int dp[200][201];
int a[200];

int DP(int i, int x)
{
	if(dp[i][x]!=-2)
		return dp[i][x];
	if(x==1)
	{
		if(n-i>k)
			dp[i][x]= -1;
		else
			dp[i][x]= a[i];
		return dp[i][x];
	}

	dp[i][x]=a[i];
	int j=i+1;
	int maxm=-1, tmp;
	while(j<min(n,k+i+1))
	{
		tmp=DP(j, x-1);
		if(tmp!=-1)
			maxm=max(maxm, tmp);
		++j;
	}
	if(maxm==-1)
		dp[i][x]=-1;
	else 
		dp[i][x]+=maxm;
	return dp[i][x];
}

int32_t main()
{
	cin>>n>>k>>x;

	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	for(int i=0; i<n; ++i)
		for(int j=0; j<=x; ++j)
			dp[i][j]=-2;
	int ans=-1;
	for(int i=0; i<min(n,k); ++i)
		ans=max(ans, DP(i, x));
	cout<<ans<<"\n";
}