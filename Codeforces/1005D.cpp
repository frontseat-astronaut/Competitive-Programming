#include<iostream>
#include<map>
using namespace std;
string s;

int dp[200001][3];

int prob(int i, int l, int sum)
{
	if(i>=l) return 0;
	if(dp[i][sum%3]) return dp[i][sum%3];
	if((sum+s[i]-'0')%3==0)
	{
		dp[i][sum%3]=1+prob(i+1,l,0);
		return dp[i][sum%3];
	}
	dp[i][sum%3]=max(prob(i+1,l,sum+s[i]-'0'),prob(i+1,l,0));
	return dp[i][sum%3];
}

int main()
{
	cin>>s;

	int l=s.length();	
	cout<<prob(0,l,0)<<endl;
}