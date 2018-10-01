#include<iostream>
#include<vector>
using namespace std;

struct station
{
	int x, p;
};

bool DP(int g, int s, vector<station> G, vector<int> dp[201])
{
	if(dp[g][s]==-2)
		return false;
	if(dp[g][s]!=-1)
		return true;
	int minm=2147483647;
	bool found=false;	
	for(int gas=g; gas<=200; ++gas)
	{
		if(gas<(G[s+1].x-G[s].x)) continue;
		if( DP(gas-G[s+1].x+G[s].x,s+1, G, dp) )
		{
			found=true;
			minm=min(dp[gas-G[s+1].x+G[s].x][s+1]+(gas-g)*G[s].p, minm);
		}
	}
	if(found)
		dp[g][s]= minm;
	else
		dp[g][s]=-2;
	return found;
}

int main()
{
	int T;
	cin>>T;
	int dnext=0;
	while(T--)
	{
		int d;
		if(dnext) d=dnext;
		else cin>>d;

		vector<station>G;
		int x,p;
		char ch;
		int n=0;
		while(cin>>x)
		{
			ch=getchar();
			if(ch=='\n')
			{
				dnext=x;
				break;
			}
			cin>>p;
			if(x<=d)
			{
				G.push_back({x,p});
				n++;
			}
		}
		G.push_back({d,0});
//		cout<<G[0].x<<endl;

		vector<int> dp[201];
		for(int g=0; g<201; ++g)
		{
			vector<int> row(n+1,-1);
			dp[g]=row;
		}

		for(int i=0; i<100; ++i)
		{
			dp[i][n]=-2;
		}
		for(int i=100; i<=200; ++i)
		{
			dp[i][n]=0;
		}

		if(G[0].x>100)
			cout<<"Impossible"<<endl;
		else if(DP(100-G[0].x, 0, G, dp))
			cout<<dp[100-G[0].x][0]<<endl;
		else
			cout<<"Impossible"<<endl;
		if(T) cout<<endl;
/*
		for(int g=0; g<201; ++g)
		{
			for(int s=0; s<n+1; ++s)
			{
				cout<<dp[g][s]<<"\t";
			}
			cout<<endl;
		}
*/
	}
}
