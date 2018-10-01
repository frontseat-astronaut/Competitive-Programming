#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int n;
	cin>>n;
	int maxm=0;
	for(int i=0; i<n; ++i)
	{
		int x,y;
		cin>>x>>y;
		if(maxm<x+y)
			maxm=x+y;
	}
	cout<<maxm<<endl;
}