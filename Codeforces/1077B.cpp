#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	int n;
	cin>>n;
	bool a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int cnt=0;
	for(int i=1; i<n-1; ++i)
	{
		if(a[i-1] && !a[i] && a[i+1])
		{
			a[i+1]=0;
			++cnt;
		}
	}
	cout<<cnt<<endl;
}