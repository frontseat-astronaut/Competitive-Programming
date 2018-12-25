#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long
using namespace __gnu_pbds;
using namespace std;

typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> tr;

int32_t main()
{
    tr psums;
	int n, t;
	cin>>n>>t;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int sum=0, ans=0;
	psums.insert({0,-1})
	for(int i=0; i<n; ++i)
	{
		sum+=a[i];
		ans+=i-psums.order_of_key({sum-t+1,-2})+1;
		psums.insert({sum,i});
	}
	cout<<ans<<endl;
}