#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int ang, n=0, dx, lcm;
		bool found=0;
		cin>>ang;
		lcm=(180*ang)/__gcd(ang, (int)180);
		for(int k=lcm; k/ang<=998244353; k+=lcm)
		{
			n=k/ang; dx=k/180;
			// cout<<n<<" "<<dx<<"\n";
			if(dx<=n-2 && dx>=1)
			{
				found=1;
				break;
			}
		}
		if(found)
		{
			cout<<n<<"\n";
		}
		else
			cout<<-1<<"\n";
	}
}