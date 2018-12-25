#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
	int n, k;
	cin>>n>>k; 
	int a[n];
	map<int,bool>x;
	int c=(1<<k)-1;
	int ans=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		if(x[a[i]])
		{
			x[a[i]]=0;
			a[i]=a[i]^c;
		}
		else if(!a[i])
		{
			if(!x[a[i]^c])
			{
				a[i]=a[i]^c;
			}
		}
		x[a[i]]=1;
		if(!a[i]) ans--;
	}
	int l=-1, r=0, prevr=0;
	map<int,int>y;
	while(1)
	{
		if(r==n)
		{
			ans+=(max(prevr-l-1,(int)0))*(r-prevr)+(r-prevr)*(r-prevr+1)/2;
			break;
		}
		if(y[a[r]])
		{
			ans+=(max(prevr-l-1,(int)0))*(r-prevr)+(r-prevr)*(r-prevr+1)/2;
			do
			{
				l++;
				y[a[l]]--;
			}
			while(a[l]!=a[r]);
			prevr=r;
		}
		y[a[r]]++;
		r++;
	}
	cout<<ans;
}