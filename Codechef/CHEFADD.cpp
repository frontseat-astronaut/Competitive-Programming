#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[32][32][32][2];
int A, B, C, cb, k;

int rtl(int i, int bb, int ba, int b)
{
	if(dp[i][bb][ba][b]!=-1)
		return dp[i][bb][ba][b];
	k=(1<<i);
	if(C<k)
	{
		if(ba>0 || b==1 || bb>0)
		{
			dp[i][bb][ba][b]=0;
		}
		else
		{
			dp[i][bb][ba][b]=1;
		}
		return dp[i][bb][ba][b];
	}
	cb=(k&C);
	dp[i][bb][ba][b]=0;
	if(cb)
	{
		if(b)
		{
			if(bb>0 && ba>0)
			{
				dp[i][bb][ba][b]+=rtl(i+1, bb-1, ba-1, 1);
			}
			dp[i][bb][ba][b]+=rtl(i+1, bb, ba, 0);
			return dp[i][bb][ba][b];
		}
		if(bb>0)
		{
			dp[i][bb][ba][b]+=rtl(i+1, bb-1, ba, 0);
		}
		if(ba>0)
			dp[i][bb][ba][b]+=rtl(i+1, bb, ba-1, 0);
		return dp[i][bb][ba][b];
	}

	if(b)
	{
		if(ba>0)
		{
			dp[i][bb][ba][b]+=rtl(i+1, bb, ba-1, 1);
		}
		if(bb>0)
			dp[i][bb][ba][b]+=rtl(i+1, bb-1, ba, 1);
		return dp[i][bb][ba][b];		
	}
	if(bb>0 && ba>0)
	{
		dp[i][bb][ba][b]+=rtl(i+1, bb-1, ba-1, 1);
	}
	dp[i][bb][ba][b]+=rtl(i+1, bb, ba, 0);
	return dp[i][bb][ba][b];

}
int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{		
		cin>>A>>B>>C;
		int ba=0, bb=0, bc;
		while(A )
		{
			ba+=(A&1);
			A>>=1;
		}
		while(B)
		{
			bb+=(B&1);
			B>>=1;
		}
		if(ba<bb)
		{
			swap(ba, bb);
		}
		for (int i = 0; i < 32; ++i)
		{
			for (int j = 0; j < 32; ++j)
			{
				for (int l = 0; l < 32; ++l)
				{
					for (int m = 0; m < 2; ++m)
					{
						dp[i][j][l][m]=-1;
					}
				}
			}
		}
		cout<<rtl(0,bb,ba,0)<<endl;
	}
}