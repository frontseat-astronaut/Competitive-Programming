#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a, b, k;
		cin>>a>>b>>k;
		int ans=a*(k-k/2)-b*(k/2);
		cout<<ans<<endl;
	}
}