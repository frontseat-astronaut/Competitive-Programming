#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	int n, s;
	cin>>n>>s;
	int a[n];
	int sm=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		sm+=a[i];
	}
	if(n==1)
	{
		if(s>a[0])
			cout<<-1;
		else
			cout<<a[0]-s;
		return 0;
	}
	while(s)
	{
		sort(a,a+n);
		if(a[0]==a[n-1])
		{
			if(sm<s)
			{
				cout<<-1;
			}
			else
			{
				int rounds=ceil((double)s/n);
				cout<<a[0]-rounds;
			}
			return 0;
		}
		if(s>a[n-1]-a[0])
		{
			s-=a[n-1]-a[0];
			sm-=a[n-1]-a[0];
			a[n-1]=a[0];
		}
		else
		{
			a[n-1]-=s;
			sm-=s;
			s=0;
		}
	}

	if(s)
	{
		cout<<-1<<"\n";
	}
	else
		cout<<a[0]<<"\n";
}