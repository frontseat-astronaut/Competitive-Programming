#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int n, ai;
	cin>>n;
	int cnt[5]={};
	for (int i = 0; i < n; ++i)
	{
		cin>>ai;
		cnt[ai]++;
	}
	double dp[305][305][305]={};
	for(int k=0; k<=n; ++k)
	{
	    for(int j=0; j<=n; ++j)
	    {
	        for(int i=0; i<=n; ++i)
	        {
	            if(i+j+k)
	                dp[i][j][k]+=n;
	            if(k)
	                dp[i][j][k]+=k*dp[i][j+1][k-1];
	            if(j)
	                dp[i][j][k]+=j*dp[i+1][j-1][k];
	            if(i)
	                dp[i][j][k]+=i*dp[i-1][j][k];
	            if(i+j+k)
	                dp[i][j][k]=(double)dp[i][j][k]/(i+j+k);
	           // dp[i][j][k]=k*(1+dp[i][j+1][k-1]) + j*(1+dp[i+1][j-1][k]) + i*(1+dp[i-1][j][k]);
	        }
	    }
	}
	printf("%.9f",dp[cnt[1]][cnt[2]][cnt[3]]);
}