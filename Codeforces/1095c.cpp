#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	int n, k, j, i, cnt=0;
	cin>>n>>k;
	int a[35]={};

	for(j=1, i=0; j<=n; j<<=1, ++i)
	{
		if(n&j)
		{
			++cnt;
			a[i]++;
		}
	}
	if(cnt>k || n<k)
	{
		cout<<"NO";
	}
	else
	{
		i--;
		for( ; i>0; --i)
		{
			while(a[i] && cnt<k)
			{
				a[i]--;
				a[i-1]+=2;
				cnt++;
			}
		}
		if(cnt<k)
		{
			cout<<"NO\n";
			exit(0);
		}
		
		cout<<"YES\n";
		for(int i=0; i<35; ++i)
		{
			while(a[i])
			{
				cout<<(1<<i)<<' ';
				a[i]--;
			}
		}
	}
}