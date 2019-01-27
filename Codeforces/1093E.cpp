#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
using namespace __gnu_pbds; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
int n, m, type;
ordered_set tr[200000];
void add(pii x, int delta)
{
	for(int i=x.ff; i<n; i=(i|(i+1)))
		if(delta==1)
			tr[i].insert(x.ss);
		else tr[i].erase(x.ss);
}
int quer(pii x)
{
	int ret=0;
	for (int i = x.ff; i >=0 ; i=(i&(i+1))-1)
	{
		ret+=tr[i].order_of_key(x.ss+1);
	}
	return ret;
}
int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>m;
	int ai;
	pii pts[n];
	int b[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>ai;
		pts[ai-1].ff=i;
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>ai;
		b[i]=ai;
		pts[ai-1].ss=i;
	}
	for (int i = 0; i < n; ++i)
	{
		add(pts[i],1);
	}
	while(m--)
	{
		cin>>type;
		if(type==1)
		{
			int la, lb, ra, rb;
			cin>>la>>ra>>lb>>rb;
			la--, ra--, lb--, rb--;
			cout<<(quer({ra, rb})-quer({ra, lb-1})-quer({la-1, rb})+quer({la-1, lb-1}))<<"\n"; 
		}
		else
		{
			int x, y;
			cin>>x>>y;
			add( pts[b[x-1]-1], -1 );
			add( pts[b[y-1]-1], -1 );
			swap(pts[b[y-1]-1].ss, pts[b[x-1]-1].ss);
			swap(b[x-1],b[y-1]);
			add(pts[b[x-1]-1], 1);
			add(pts[b[y-1]-1], 1);
		}
	}
}