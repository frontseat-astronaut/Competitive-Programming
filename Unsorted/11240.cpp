#include<iostream>
#include<stdio.h>
#define up true
#define down false
using namespace std;
/*
int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		int n;
		scanf("%d",&n);
		int f[n];
		for(int i=0; i<n; ++i) scanf("%d",&f[i]);

		int dp[2][n];
		dp[0][n-1]=dp[1][n-1]=1;

		int maxm=0;
		for(int i=n-2; i>=0; --i)
		{
			int max1=0, max0=0;
			for(int j=i+1; j<n; ++j)
			{
				if(f[j]<f[i])
					max0=max(max0, dp[0][j]);

				if(f[j]>f[i])
					max1=max(max1, dp[1][j]);
			}
			dp[0][i]=max1+1, dp[1][i]=max0+1;
			
			maxm=max(maxm, dp[1][i]);
		}
		printf("%d\n",maxm);
	}
}
*/
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		int f[N];
		for(int i=0; i<N; ++i) cin>>f[i];

		bool dir=down;
		int last=f[0];
		int ans=1;
		for(int i=1; i<N; ++i)
		{
			if(dir==down)
			{
				if(f[i]<last)
				{
					ans++;
					last=f[i];
					dir=up;
				}
				else
					last=f[i];
			}
			if(dir==up)
			{
				if(f[i]>last)
				{
					ans++;
					last=f[i];
					dir=down;
				}
				else
					last=f[i];
			}
		}
		cout<<ans<<endl;
	}
}