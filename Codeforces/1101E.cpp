#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int maxx=0, maxy=0;
	while(n--)
	{
		char q;
		cin>>q;
		if(q=='+')
		{
			int x, y;
			cin>>x>>y;
			if(x>y)
			{
				swap(x,y);
			}
			maxx=max(x, maxx);
			maxy=max(y, maxy);
		}
		else
		{
			int h, w;
			cin>>h>>w;
			if(h>w)
			{
				swap(h,w);
			}
			if(maxx<=h && maxy<=w)
			{
				cout<<"YES\n";
			}
			else
				cout<<"NO\n";
		}
	}
}