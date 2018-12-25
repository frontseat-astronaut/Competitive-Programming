#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
int n, a;
vector<int>v;
int check(int qty, int id)
{
	int i=0;
	int cnt=qty;
	auto next=v.begin()+id;
	while(next!=v.end())
	{
		// cout<<next-v.begin()<<" ";
		next=lower_bound(next+1, v.end(), qty<<1);
		if(next==v.end())
			break;
		qty=qty<<1;
		cnt+=qty;
	}
	// cout<<next-v.begin()<<" ";
	// cout<<": "<<cnt<<endl;
	return cnt;
}

int32_t main()
{
	cin>>n;
	map<int,int>e;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		e[a]++;
	}
	for(auto ei:e)
	{
		v.push_back(ei.ss);
	}
	sort(v.begin(), v.end());
	// for(auto vi: v)
	// 	cout<<vi<<" ";
	// cout<<"\n";
	n=v.size();
	int maxm=0;
	for(int j=0; j<n; ++j)
	{
		for(int i=1; i<=v[j]; ++i)
		{
			maxm=max(check(i, j), maxm);
		}
	}
	
	cout<<maxm<<endl;
}