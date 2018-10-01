#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	int n, m, d;
	cin>>n>>m>>d;

	bool r[m]={};
	int a[n];
	int index[m], day[n];
	for(int i=0; i<n; ++i)
	{
		cin>>a[i];
		index[a[i]-1]=i;
		r[a[i]-1]=1;
	}

	stack<int> days;
	for(int i=0; i<n; ++i)
	{
		
	}
}