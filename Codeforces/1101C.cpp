#include<bits/stdc++.h>
using namespace std;
#define int long long
struct inter
{
	int ff, ss;
	int idx;
	bool operator<(inter const &other) const
	{
		if(ff!=other.ff)
			return ff<other.ff;
		return ss<other.ss;
	}
};
int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		inter seg[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>seg[i].ff>>seg[i].ss;
			seg[i].idx=i;
		}
		sort(seg, seg+n);
		int grp[n];
		int l=0, r=0;
		int cnt=0;
		for(auto x:seg)
		{
			if(x.ff>r)
			{
				++cnt;
				l=x.ff;
				r=x.ss;
				grp[x.idx]=min(cnt, (int)2);
			}
			else
			{
				r=max(r, x.ss);
				grp[x.idx]=min(cnt, (int)2);
			}
		}
		if(cnt<2)
		{
			cout<<-1<<"\n";
		}
		else
		{
			for (int i = 0; i < n; ++i)
			{
				cout<<grp[i]<<' ';
			}
			cout<<"\n";
		}
	}
}