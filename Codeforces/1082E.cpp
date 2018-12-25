//とても良い!
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ff first
#define ss second

int main()
{
	int n, c;
	cin>>n>>c;
	int a[n], cnt[n+1]={};
	map<int,int>li;
	int dp[n+1]={};
	auto it=li.begin();
	int maxm=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		a[i]-=c;
		cnt[i+1]=cnt[i]+(a[i]==0);
	}
	for(int i=0; i<n; ++i)
	{
		if(!a[i])
			continue;
		it=li.find(a[i]);
		if(it==li.end())
		{
			li[a[i]]=i;
			dp[i]=1;
			maxm=max(dp[i], maxm);
			continue;
		}
		dp[i]=max(dp[(*it).ss]+1-cnt[i+1]+cnt[(*it).ss], 1);
		li[a[i]]=i;
		maxm=max(dp[i], maxm);
	}
	cout<<maxm+cnt[n]<<endl;
}