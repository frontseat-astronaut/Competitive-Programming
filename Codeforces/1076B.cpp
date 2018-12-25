#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ff  first
#define ss second
using namespace std;

int32_t main()
{
	int n;
	cin>>n;
	if(!(n&1))
	{
		cout<<n/2<<endl;
		return 0;
	}
	int p=n;
	for(int i=2; i*i<=n; ++i)
	{
		if(n%i==0)
		{
			p=i;
			break;
		}
	}
	if(p&1 && n&1)
	{
		cout<<(1+(n-p)/2)<<endl;
	}
	else
		cout<<n/p<<endl;
}