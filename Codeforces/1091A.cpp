#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
	int y, b, r;
	cin>>y>>b>>r;
	int x=min(y, b-1);
	x=min(x, r-2);
	cout<<(3*x+3);
}