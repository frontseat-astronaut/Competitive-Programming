#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int len;
	int tmp;
	cin>>n;

	int a[n];
	vector<int>p[n];
	int dp[n];

	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	for(int i=0; i<n; ++i)
	{
		len=1;
		for(int j=i, k=i; j>=0 && k<n; ++k, --j, len+=2)
		{
			if(a[k]!=a[j])
				break;
			p[j].push_back(len);
		}
		len=2;
		for(int j=i, k=i+1; j>=0 && k<n; ++k, --j, len+=2)
		{
			if(a[k]!=a[j])
				break;
			p[j].push_back(len);
		}
	}
	for(int i=n-1; i>=0; --i)
	{
		dp[i]=INT_MAX;
		for(auto len: p[i])
		{
			tmp=1;
			if(len+i<n)
				tmp+=dp[len+i];
			dp[i]=min(dp[i], tmp);
		}
	}
	cout<<dp[0]<<endl;
}