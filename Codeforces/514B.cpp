#include<iostream>
#include<algorithm>
#include<set>
#define pii pair<int,int>
#define x first
#define y second
using namespace std;

int main()
{
	int n, x, y, x0, y0, g;
	set<pii>dir;
	cin>>n;
	cin>>x0>>y0;
	for (int i = 0; i < n; ++i)
	{
		cin>>x>>y;
		x-=x0, y-=y0;

		if(x==0)
			dir.insert({0,1});
		else if(y==0)
			dir.insert({1,0});
		else
		{
			g=__gcd(x,y);
			x/=g, y/=g;
			dir.insert({x,y});
		}
	}
	cout<<dir.size()<<endl;
}