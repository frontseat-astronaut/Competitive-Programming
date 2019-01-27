#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
int const N=1e6+1;
int maxm, minm;
pii mintr[N<<1], maxtr[N<<1];
int n;

void build()
{
	for(int i=n-1; i>0; i--)
	{
		if(mintr[i<<1].ff<mintr[i<<1|1].ff)
		{
			mintr[i]=mintr[i<<1];
		}
		else
		{
			mintr[i]=mintr[i<<1|1];
		}
		if(maxtr[i<<1].ff>maxtr[i<<1|1].ff)
		{
			maxtr[i]=maxtr[i<<1];
		}
		else
		{
			maxtr[i]=maxtr[i<<1|1];
		}
	}
}
pii querymax(int l, int r)
{
	pii ret={LLONG_MIN, -1};
	for(l+=n, r+=n; l<r; l>>=1, r>>=1)
	{
		if(l&1)
		{
			if(ret.ff<maxtr[l].ff)
			{
				ret=maxtr[l];
			}
			l++;
		}
		if(r&1)
		{
			r--;
			if(ret.ff<maxtr[r].ff)
			{
				ret=maxtr[r];
			}
		}
	}
	return ret;
}
pii querymin(int l, int r)
{
	pii ret={LLONG_MAX, -1};
	for(l+=n, r+=n; l<r; l>>=1, r>>=1)
	{
		if(l&1)
		{
			if(ret.ff>mintr[l].ff)
			{
				ret=mintr[l];
			}
			l++;
		}
		if(r&1)
		{
			r--;
			if(ret.ff>mintr[r].ff)
			{
				ret=mintr[r];
			}
		}
	}
	return ret;
}

void dncmax(int L, int R)
{
	if(L+1>=R-1)
		return;
	pii mx=querymax(L+1,R);
	maxm+=mx.ff*((mx.ss-L)*(R-mx.ss)-1);
	dncmax(L,mx.ss);
	dncmax(mx.ss,R);
}
void dncmin(int L, int R)
{
	if(L+1>=R-1)
		return;
	pii mn=querymin(L+1,R);
	minm+=mn.ff*((mn.ss-L)*(R-mn.ss)-1);
	dncmin(L,mn.ss);
	dncmin(mn.ss,R);
}

int32_t main()
{
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		int ai;
		cin>>ai;
		mintr[i+n]={ai, i};
		maxtr[i+n]={ai, i};
	}
	build();
// 	cout<<querymin(0, 3).ff<<"\n";
	dncmax(-1, n);
	dncmin(-1, n);
	cout<<maxm-minm;
}