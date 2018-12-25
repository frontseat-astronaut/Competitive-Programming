#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	int n, m;
	cin>>n>>m;
	int a[n], sum=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(n==1)
	{
		cout<<0<<endl;
		exit(0);
	}
	sort(a, a+n);
	int cnt=0, curr=a[n-1];
	for(int i=n-2; i>=0; --i)
	{
		if(curr<=a[i])
		{
			curr--;
			++cnt;
			continue;
		}
		cnt+=curr-a[i];
		curr=a[i];
	}
	if(curr<=0)
	{
		curr--;
		++cnt;
	}
	else
		cnt+=curr;
	cout<<sum-cnt<<endl;
}