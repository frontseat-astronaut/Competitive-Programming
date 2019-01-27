#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int n, k;
	cin>>n>>k;
	int sum[2]={};
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		sum[a[i]>0]++;
	}
	int maxm=0;
	for(int i=0; i<n; ++i)
	{
		int tmp[2];
		tmp[0]=sum[0];
		tmp[1]=sum[1];
		for(int j=i; j<n; j+=k)
		{
			tmp[a[j]>0]--;
		}
		for(int j=i-k; j>=0; j-=k)
		{
			tmp[a[j]>0]--;
		}
		maxm=max(maxm, (int)fabs(tmp[0]-tmp[1]) );
	}
	cout<<maxm;
}