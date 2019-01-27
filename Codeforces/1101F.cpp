#include<bits/stdc++.h>
using namespace std;
#define int long long
struct truck
{
	int l, r, c, k;
	bool operator<(truck const &o) const
	{
	    if(o.l!=l)
	        return l<o.l;
	    if(k!=o.k)
	        return k<o.k;
	    if(r!=o.r)
	        return r<o.r;
	    return c>o.c;
	}
};
int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n, m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1; i<=n; ++i)
	{
		cin>>a[i];
	}
	vector<truck>tr(m);
	for(int i=0 ;i<m; ++i)
	{
		cin>>tr[i].l>>tr[i].r>>tr[i].c>>tr[i].k;
	}
	sort(tr.begin(), tr.end());
	int ans=0;
	for(int idx=0; idx<m;)
	{
		int l=tr[idx].l;
		int dp[405][405]={};
		for(int r=l+1; r<=n; ++r)
		{
			dp[r][0]=a[r]-a[r-1]+dp[r-1][0];
			while(idx<m && tr[idx].l==l && tr[idx].r==r && tr[idx].k==0)
		    {
		        ans=max(ans,tr[idx].c*dp[r][0]);
		        idx++;
		    }	
		}
		for(int k=1; k<=n; ++k)
		{
		    int op=l;
			for(int r=l+1; r<=n; ++r)
			{
				while(op<r && max(a[r]-a[op],dp[op][k-1])>=max(a[r]-a[op+1], dp[op+1][k-1]))
					++op;
				// op--;
				dp[r][k]=max(dp[op][k-1], a[r]-a[op]);

				while(idx<m && tr[idx].l==l && tr[idx].r==r && tr[idx].k==k)
				{
				    ans=max(ans,tr[idx].c*dp[r][k]);
				    idx++;
				}				
			}
		}
	}
	cout<<ans;	
}