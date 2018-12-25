#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int n, m;
	cin>>n>>m;
	int ans=0;
	int cnt[m]={};
	int sqmod[m]={};
	for(int i=0; i<m; ++i)
	{
		cnt[i]=n/m;
		if(i)
			cnt[i]+=((n%m)>=i);

		sqmod[(i*i)%m]+=cnt[i];
	}
	for(int i=0; i<m; ++i)
	{
//		cout<<cnt[i]<<' ';
		ans+=sqmod[i]*sqmod[(m-i)%m];
	}

	cout<<ans<<endl;
}