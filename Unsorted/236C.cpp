#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

int lcm(int x, int y, int z)
{
	int l=x*y/__gcd(x,y);
	l=l*z/__gcd(l,z);
	return l;
}

int32_t main()
{
	int n;
	cin>>n;
	if(n<=7 && n>=3)
		cout<<lcm(n, n-1, n-2);
	else if (n<=2)
		cout<<n;
	else if(n%2==0)
	{
		cout<<max(lcm(n, n-1, n-3), lcm(n-1,n-2,n-3));
	}
	else
		cout<<lcm(n,n-1,n-2);
	cout<<endl;
}