#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=100001;
int n, maxm=0;

int32_t main()
{
	cin>>n;
	int ans=0;
	for(int i=2; i<=n; ++i)
	{
		for(int j=i<<1; j<=n; j+=i)
		{
			ans+=4*(j/i);		
		}
	}
	cout<<ans<<endl;
}