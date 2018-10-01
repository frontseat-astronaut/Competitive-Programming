#include<iostream>
#define int long long
using namespace std;

int32_t main()
{
	int T, N;
	int A[1001], dp[1001][2]={};
	cin>>T;
	while(T--)
	{
		cin>>N;
		for (int i = 0; i < N; ++i)
		{
			cin>>A[i];
		}
		dp[N-1][0]=1;
		dp[N-1][1]=1;
		for(int i=N-2; i>=0; --i)
		{
			int maxm0=1, maxm1=1;
			for(int j=i+1; j<N; ++j)
			{
				if(A[j]>A[i])
				{
					maxm0=max(maxm0, dp[j][0]+1);
					maxm0=max(maxm0, dp[j][1]+1);
				}
				else if(A[j]<A[i])
				{
					maxm1=max(maxm1, dp[j][1]+1);
				}
			}
			dp[i][0]=maxm0, dp[i][1]=maxm1;
		}
		cout<<max(dp[0][0],dp[0][1])<<endl;
	}
}