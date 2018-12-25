#include<bits/stdc++.h>
#define int long long
using namespace std;;

int32_t main()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}	
	int minm=LLONG_MAX, sm;
	for(int x=0; x<n; ++x)
	{
		sm=0;
		for(int i=0; i<n; ++i)
		{
			sm+=2*a[i]*(fabs(i-x)+i+x);
		}
		// cout<<minm<<endl;
		minm=min(sm, minm);
	}
	cout<<minm<<endl;
}