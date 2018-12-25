#include<iostream>
#include<math.h>
#define int long long
using namespace std;

int32_t	 main()
{
	int n, k;
	cin>>n>>k;

	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int g, x, q;
	int ans=0;
	
	q=ceil((double)a[n-1]/k);
	ans+=q;
	g=q*k-a[n-1];
	for(int i=n-2; i>=0; --i)
	{
		q=ceil((double)(a[i]-g)/k);
		g=q*k-a[i]+g;
		ans+=q;
	}
	if(g)
		ans++;
	cout<<ans<<endl;
}