#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long 
#define ff first
#define ss second
#define pb push_back
using namespace std;

int32_t main()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int cnt=0, maxm=0;
	for (int i = 0; i < n-1; ++i)
	{
		if(i==0 && n>1)
		{
			if(a[0]==1 && a[1]-a[0]==1)
				++cnt;
			else
			{
				maxm=max(cnt,maxm);
				cnt=0;
			}
			continue;
		}
		if(a[i]-a[i-1]==1 && a[i+1]-a[i]==1)
			++cnt;
		else
		{
			maxm=max(cnt,maxm);
			cnt=0;
		}
	}
	if(n>1)
	{
		if(a[n-1]-a[n-2]==1 && a[n-1]==1000)
			++cnt;
		maxm=max(cnt,maxm);
		cnt=0;
	}
	cout<<maxm<<endl;
}