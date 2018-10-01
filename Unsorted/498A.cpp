#include<iostream>
#define int long long
using namespace std;

int32_t main()
{
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int n, ans=0;
	cin>>n;
	for(int i=0; i<n; ++i)
	{
		int a, b, c;
		cin>>a>>b>>c;
		if(((x1*a+y1*b+c)<0 &&(x2*a+y2*b+c)>0)||((x1*a+y1*b+c)>0 &&(x2*a+y2*b+c)<0))
		{
			ans++;
		}
	}
	cout<<ans<<endl;
}