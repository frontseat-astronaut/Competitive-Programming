#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int pcnt[N];

void seive()
{
	for(int i=2; i<N; ++i)
	{
		if(!pcnt[i])
		{
			for(int j=i; j<N; j+=i)
			{
				pcnt[j]++;
			}
		}
	}
}

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	seive();
	// for(int i=2; i<=10; ++i)
	// 	cout<<pcnt[i]<<" ";
	// cout<<"\n";

	int t;
	cin>>t;
	while(t--)
	{
		int n, ai, cnt, ans=0;
		int a[N]={};
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>ai;
			a[ai]++;
		}
		for(int i=2; i<N; ++i)
		{
			cnt=0;
			for(int j=0; j<N; j+=i)
			{
				cnt+=a[j];
			}
			ans=max(ans, cnt*pcnt[i]);
		}
		cout<<ans<<endl;
	}
}