#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ff first
#define ss second
#define int long long
bool cmp1(pii a, pii b)
{
	if(a.ff==b.ff)
		return a.ss>b.ss;
	return a.ff<b.ff;
}
int32_t main()
{
	int n, k;
	cin>>n>>k;
	pii a[n];
	vector<int>unused;
	for(int i=0; i<n; ++i)
		cin>>a[i].ff;
	for(int i=0; i<n; ++i)
		cin>>a[i].ss;
	sort(a, a+n, cmp1);
	int i=0, tmp;
	int cnt=0;
	// for(int i=0; i<n; ++i)
	// 	cout<<a[i].ff<<" ";
	// cout<<endl;
	while(i<n)
	{
		tmp=a[i].ff;
		cnt++;
		i++;
		while(i<n && tmp==a[i].ff )
		{
			unused.push_back(a[i].ss);
			i++;
		}
	}
//	cout<<cnt<<endl;
	cnt=k-cnt;
	sort(unused.begin(), unused.end());
	int ans=0;
	for(int i=0; i<cnt; ++i)
		ans+=unused[i];
	cout<<ans<<endl;
}