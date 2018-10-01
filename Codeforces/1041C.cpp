#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	int a,b,x,y;
	cin>>a>>b>>x>>y;

	int g=__gcd(x,y);
	x/=g, y/=g;
	cout<<min(a/x, b/y);
}