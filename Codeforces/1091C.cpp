#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int n, s;
	cin>>n;
	set<int>ans;
	for(int i=1; i*i<=n; ++i)
	{
		if(n%i==0)
		{
			s=n/i + (n/i-1)*n/2;
			ans.insert(s);
			i=n/i;
			s=n/i + (n/i-1)*n/2;
			ans.insert(s);
			i=n/i;
		}
	}
	for(int x:ans)
		cout<<x<<' ';
}