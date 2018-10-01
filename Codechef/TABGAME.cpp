#include<iostream>
#include<vector>
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N, M, Q;
	vector<vector<bool>> dp(100001,vector<bool>(100001));
	int tn, tm;
	int x,y;
	bool ml, nl;
	bool p;
	string n, m;
	cin>>T;
	while(T--)
	{
		cin>>m>>n;
		M=m.length(), N=n.length();
		
		for(int i=0; i<M; ++i)
		{
			dp[0][i+1]=(m[i]-'0');
		}
		for(int i=0; i<N; ++i)
		{
			dp[i+1][0]=(n[i]-'0');
		}

		for(int i=1; i<=N; ++i)
		{
			for(int j=1; j<=M; ++j)
			{
				dp[i][j]=(dp[i-1][j]&dp[i][j-1])^1;
				cout<<dp[i][j]<<' ';
			}
			cout<<endl;
		}
/*
		cin>>Q;
		while(Q--)
		{
			cin>>x>>y;
			cout<<dp[x][y];
		}
		cout<<endl;	
	*/
	}
}