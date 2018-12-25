#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n&1)
		{

			long long x=(1<<n)+1, y=3*(1<<n);
			long long g=__gcd(x,y);
			x/=g, y/=g;
			cout<<x<<' '<<y<<" "; 
		}
		else
		{
			long long x=(1<<n)-1, y=3*(1<<n);
			long long g=__gcd(x,y);
			x/=g, y/=g;
			cout<<x<<' '<<y<<" ";
		}
	}
}