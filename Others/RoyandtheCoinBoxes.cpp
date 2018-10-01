#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int N, M;
	cin>>N>>M;

	int start[N]={}, end[N]={};
	int dp[N]={};
	for(int i=0; i<M; ++i)
	{
		int l,r;
		cin>>l>>r;
		l--, r--;
		start[l]++;
		end[r]++;
	}
	dp[0]=start[0];
	for(int i=1; i<N; ++i)
	{
		dp[i]=start[i]+dp[i-1]-end[i-1];
	}
	sort(dp, dp+N);

	int Q;
	cin>>Q;
	while(Q--)
	{
		int X;
		cin>>X;

		cout<<(lower_bound(dp, dp+N, X)-dp)+1<<endl;
	}
}