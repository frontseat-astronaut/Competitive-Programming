#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
#define ff first
#define ss second
#define fastio() ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

struct edge
{
	int u, v, w;
	bool operator<(edge const &o) const
	{
		return w<o.w;
	}
};

int n,m,amb;
const int N=2e5+5;
pii a[N];
edge offers[N];
int rnk[N], parent[N];

void make_set()
{
	for(int i=1; i<=n; ++i)
	{
		parent[i]=i;
		rnk[i]=0;
	}
}

int find_set(int x)
{
	if(parent[x]==x)
		return x;
	return parent[x]=find_set(parent[x]);
}

void union_set(int a, int b)
{
	a=find_set(a);
	b=find_set(b);
	if(a!=b)
	{
		if(rnk[a]>rnk[b])
			swap(a, b);
		parent[a]=b;
		if(rnk[a]==rnk[b])
		{
			rnk[b]++;
		}
	}
}

int32_t main()
{
	fastio();
	cin>>n>>m;
	for(int i=1; i<=n; ++i)
	{
		cin>>a[i].ff;
		a[i].ss=i;
	}
	sort(a, a+n+1);
	for(int i=0; i<m; ++i)
	{
		int u, v, w;
		cin>>u>>v>>w;
		offers[i]={u,v,w};
	}
	sort(offers, offers+m);
	make_set();
	for(int i=0, j=2, k=0, l=1; i<n-1; ++i)
	{
		while(k<m && find_set(offers[k].u)==find_set(offers[k].v))
			k++;
		while(find_set(a[l].ss)==find_set(a[j].ss))
		{
			++j;
			if(j==n+1)
			{
				l++;
				j=l+1;
			}
		}
		if(k<m && a[j].ff+a[l].ff>offers[k].w)
		{
			union_set(offers[k].u, offers[k].v);
			amb+=offers[k].w;
			k++;
		}
		else
		{
			union_set(a[l].ss, a[j].ss);
			amb+=a[l].ff+a[j].ff;
			j++;
			if(j==n+1)
			{
				l++;
				j=l+1;
			}
		}
	}
	cout<<amb;
}