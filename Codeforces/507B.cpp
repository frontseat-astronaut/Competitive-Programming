#include<iostream>
#include<math.h>
#define int long long
using namespace std;

int32_t main()
{
	int r, x, y, x_, y_;
	cin>>r>>x>>y>>x_>>y_;
	double d=sqrt((x-x_)*(x-x_)+ (y-y_)*(y-y_));
	int ans=ceil(d/(2*r));
	cout<<ans<<endl;
}