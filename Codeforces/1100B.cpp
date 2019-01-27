#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    bt;
int32_t main()
{
	long long n, m;
	cin>>n>>m;
	long long a[m];
	bool ans[m]={};
	for (long long i = 0; i < m; ++i)
	{
		cin>>a[i];
	} 
	long long rnds=0;
	long long dist=0;
	long long cnt[n+1]={};
	bt ot;
	for (long long i = 0; i < n; ++i)
	{
		ot.insert({0, i+1});
	}
	for (long long i = 0; i < m; ++i)
	{
		if(cnt[a[i]]-rnds==0)
		{
			dist++;
		}
		cnt[a[i]]++;
		ot.erase({cnt[a[i]]-1, a[i]});
		ot.insert({cnt[a[i]], a[i]});
		if(dist==n)
		{
			rnds++;
			ans[i]=1;
			dist=ot.order_of_key({rnds+1, -1});
			dist=n-dist;
		}
	}
	for (long long i = 0; i < m; ++i)
	{
		cout<<ans[i];
	}
}