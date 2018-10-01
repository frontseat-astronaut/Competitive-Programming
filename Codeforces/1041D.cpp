#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	int n, h;
	cin>>n>>h;

	int a[n+1], d[n];
	int x1, x2, prev;
	int suma=0, sumd=0;
	int l=1, r=1;
	int maxm=0;

	a[0]=0;
	prev=-10e9-1;
	for(int i=1; i<=n; ++i)
	{
		cin>>x1>>x2;
		a[i]=x2-x1;
		suma+=a[i];
		a[i]=suma;
		d[i-1]=x1-prev;
		prev=x2;
	}
	d[0]=0;

	sumd=0;
	while(1)
	{
		if(sumd>=h)
		{
			maxm=max(a[r-1]-a[l-1]+h,maxm);
			sumd-=d[l];
			++l;
			continue;
		}
		if(r==n)
		{
			maxm=max(a[r]-a[l-1]+h, maxm);
			break;
		}
		++r;
		sumd+=d[r-1];
	}
	cout<<maxm<<endl;

}