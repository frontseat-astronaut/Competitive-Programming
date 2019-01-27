#include<bits/stdc++.h>
using namespace std;
long long m=998244353;

#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds; 

typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    bt;

long long powr(long long a, long long r)
{
	if(r==1)
		return a;
	long long tmp=powr(a, r>>1);
	tmp=(tmp*tmp)%m;
	if(r&1)
		tmp=(tmp*a)%m;
	return tmp;
}
int32_t main()
{
	long long n, cnt=0;
	cin>>n;
	long long a[n+1];
	long long ans=0;
	bool pres[n+1]={};
	long long lt[n+1]={};
	for(int i=1; i<=n; ++i)
	{
		cin>>a[i];
		if(a[i]!=-1)
		{
			pres[a[i]]=1;
		}
		else
			++cnt;
	}
	for(int i=1, cnt_=0; i<=n; ++i)
	{
		if(pres[i])
		{
			lt[i]=cnt_;
		}
		else
		{
			cnt_++;
		}
	}
	if(n==1)
	{
		cout<<0;
		exit(0);
	}
	if(cnt)
	{
		ans=( (cnt*(cnt-1))%m * powr((long long)4,m-2) )%m;
// 		cout<<ans<<endl;
		for(long long i=1, cnt_=0; i<=n; ++i)
		{
			if(a[i]!=-1)
			{
				ans=( ans + (((cnt-lt[a[i]])*cnt_)%m * powr(cnt,m-2))%m )%m;
				ans=( ans + ((lt[a[i]]*(cnt-cnt_))%m * powr(cnt, m-2))%m )%m;
				ans=(ans+m)%m;
			}
			else
				++cnt_;
		}
	}
	bt tr;
	for(long long i=1, cnt_=0; i<=n; ++i)
	{
		if(a[i]!=-1)
		{
			long long o=tr.order_of_key(a[i]);
			o=cnt_-o;
			ans=(ans + o)%m;
			tr.insert(a[i]);
			++cnt_;
		}
	}
	cout<<ans;
}