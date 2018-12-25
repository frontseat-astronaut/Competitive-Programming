#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long 
#define ff first
#define ss second
#define pb push_back
using namespace std;

int32_t main()
{
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<1<<" "<<0<<endl;
		return 0;
	}

	int m=n, i=2, ni=n;
	n=1;
	int cnt=0;
	int fcnt=0, maxm=0;
	while(m>1)
	{	
		fcnt=0;
		if(m%i==0)
			n*=i;
		while(m%i==0)
		{
			m/=i;
			++fcnt;
		}
		maxm=max(maxm, fcnt);
		++i;
	}	
	int ans=n;
	int powr=1;
	while( powr<maxm )
	{
		n=n*n;
		++cnt;
		powr=powr<<1;
	}
	if(n!=ni)
		++cnt;
	cout<<ans<<" "<<cnt<<endl;
}