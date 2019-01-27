#include<bits/stdc++.h>
using namespace std;
int n, q;
int ai, tr[];
void add(int idx, int delta)
{
	for(; idx<n; idx=idx|(idx+1))
	{
		tr[idx]+=delta;
	}
}
int sum(int r)
{
	int ret=0;
	for(; r>=0; r=r&(r+1)-1)
	{
		ret+=tr[r];
	}
	return ret;
}
int sum(int l, int r)
{
	return sum(r)-sum(l-1);
}
int32_t main()
{
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>ai;
		add(i, ai);
	}

}