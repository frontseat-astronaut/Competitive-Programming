#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
	int n, x, y;
	cin>>n>>x>>y;

	int a[n];
	int lt=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		if(a[i]<=x)
			++lt;
	}
	if(x<=y)
	{
		cout<<lt-(lt/2);
	}
	else
		cout<<n;

}