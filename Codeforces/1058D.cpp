#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	int n, m, k;
	cin>>n>>m>>k;

	if((2*n*m)%k!=0)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;

	int a,b;
	if(k%2==0)
	{
		k/=2;
		int g=__gcd(n,k);
		a=n/g;
		k/=g;
		b=m/k;
	}
	else 
	{
		int g=__gcd(n,k);
		a=n/g;
		b=1;
		if(a<n)
		{
			a*=2;
		}
		else
		{
			b*=2;
		}
		k/=g;
		b*=m;
		b=b/k;
	}
	cout<<"0 0\n";
	cout<<"0 "<<b<<endl;
	cout<<a<<" 0"<<endl;
}