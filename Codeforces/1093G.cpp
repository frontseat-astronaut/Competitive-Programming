#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
const int N=2e5, K=5;
int n, k;
pii tr[N<<1][1<<K];
int pnts[N][K];
int comp(int x)
{
	int tmp=0;
	for(int i=1; i<(1<<k); i<<=1)
	{
		if(x&i)
			continue;
		tmp|=i;
	}
	return tmp;
}
void build()
{
	for(int i=n-1; i>0; i--)
	{
		for(int j=0; j<(1<<k); ++j)
		{
			if(tr[i<<1][j].ff>tr[i<<1|1][j].ff)
			{
				tr[i][j]=tr[i<<1][j];
			}
			else
				tr[i][j]=tr[i<<1|1][j];
		}
	}
}

void update(int idx)
{
	for(int j=0; j<(1<<k); ++j)
	{
		int sm=0;
		for(int l=1, m=0; l<(1<<k); l<<=1, m++)
		{
			if(l&j)
				sm-=pnts[idx][m];
			else
				sm+=pnts[idx][m];
		}
		tr[idx+n][j]={sm, idx};
	}
	for(int i=(idx+n)>>1; i>0; i>>=1)
	{
		for(int j=0; j<(1<<k); ++j)
		{
			if(tr[i<<1][j].ff>tr[i<<1|1][j].ff)
			{
				tr[i][j]=tr[i<<1][j];
			}
			else
				tr[i][j]=tr[i<<1|1][j];
		}
	}
}

int query(int l, int r)
{
	pii maxm[1<<5];
	for(int j=0; j<(1<<k); ++j)
	{
		maxm[j]={LLONG_MIN, -1};
	}
	for(l+=n, r+=n; l<r; l>>=1, r>>=1)
	{
		if(l&1)
		{
			for(int j=0; j<(1<<k); ++j)
			{
				if(maxm[j].ff<tr[l][j].ff)
				{
					maxm[j]=tr[l][j];
				}
			}
			l++;
		}
		if(r&1)
		{
			r--;
			for(int j=0; j<(1<<k); ++j)
			{
				if(maxm[j].ff<tr[r][j].ff)
				{
					maxm[j]=tr[r][j];
				}
			}
		}
	}
	// cout<<"query:\n";
	// for(int j=0; j<(1<<k); ++j)
	// 	cout<<maxm[j].ff<<"\n";
	// cout<<"\n";
	int ans=0;
	for(int i=0; i<(1<<k); ++i)
	{
		int j=comp(i);
		int dist=0;
		for(int l=0; l<k; ++l)
		{
			dist+=fabs(pnts[maxm[i].ss][l]-pnts[maxm[j].ss][l]);
		}
		ans=max(ans, dist);
	}
	return ans;
}

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	for (int i = 0; i < n; ++i)
	{
		int sm=0;
		for (int j = 0; j < k; ++j)
		{
			cin>>pnts[i][j];
		}
		for(int j=0; j<(1<<k); ++j)
		{
			int sm=0;
			for(int l=1, m=0; l<(1<<k); l<<=1, m++)
			{
				if(l&j)
					sm-=pnts[i][m];
				else
					sm+=pnts[i][m];
			}
			tr[i+n][j]={sm, i};
		}
	}
	build();
	// cout<<tr[n][0].ff<<"\n";
	int q;
	cin>>q;
	while(q--)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int i;
			cin>>i;
			i--;
			for(int j=0; j<k; ++j)
			{
				cin>>pnts[i][j];
			}
			update(i);
		}
		else
		{
			int l,r ;
			cin>>l>>r;
			l--;
			cout<<query(l,r)<<"\n";
		}
	}
}