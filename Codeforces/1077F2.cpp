#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, k, x, h, tmp, l, r, ans=-1;
int a[5000];
int dp[5000][5001];
int st[70][5001];

void build(int x)
{
	for(int i=0; i<n; ++i)
		st[0][i]=dp[i][x];
	for(int j=1; j<=h; ++j)
	{
		for(int i=0; i+(1<<j)<=n; ++i)
		{
			st[j][i]=-1;
			if(st[j-1][i]!=-1)
				st[j][i]=st[j-1][i];
			if(st[j-1][i+(1<<(j-1))]!=-1)
				st[j][i]=max(st[j][i], st[j-1][i+(1<<(j-1))]);
		}
	}
}

int query(int l, int r)
{
	int p=log2(r-l);
	return max(st[p][l], st[p][r-(1<<p)]);
}

int32_t main()
{	
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>k>>x;
	h=floor(log2(n));
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	for(int i=0; i<5000; ++i)
		for(int j=0; j<=5000; ++j)
			dp[i][j]=-1;

	for(int i=0; i<k; ++i)
	{
		dp[n-1-i][1]=a[n-1-i];
	}	
	for(int j=2; j<=x; ++j)
	{
		build(j-1);
		for(int i=0; i<=n-j; ++i)
		{
			l=i+1, r=min(i+k+1, n);
			tmp=query(l, r);
			if(tmp!=-1)
				dp[i][j]=a[i]+tmp;
		}
	}

	// for(int i=1; i<=x; ++i)
	// {
	// 	for(int j=0; j<n; ++j)
	// 	{
	// 		cout<<dp[j][i]<<' ';
	// 	}
	// 	cout<<endl;
	// }

	for(int i=0; i<min(k, n); ++i)
		ans=max(ans, dp[i][x]);
	cout<<ans<<endl;
}
