#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
const int N=(1e5+1);
int n;
pii t[N<<1];

void build()
{
	int l, r, m;
	for(int i=n-1; i>0; --i)
	{
		l=i<<1;
		r=i<<1|1;
		if(t[l].ff>t[r].ff)
			m=l;
		else
			m=r;
		t[i].ff=t[m].ff;
		t[i].ss=max(t[m].ss, t[m^1].ff);
	}
}

void update(int x, int p)
{
	int l, r, m;
	x+=n;
	t[x]={p,LLONG_MIN};
	for(int i=x>>1; i>0; i>>=1)
	{
		l=i<<1;
		r=i<<1|1;
		if(t[l].ff>t[r].ff)
			m=l;
		else
			m=r;
		t[i].ff=t[m].ff;
		t[i].ss=max(t[m].ss, t[m^1].ff);
	}
}

pii query(int l, int r)
{
	pii qu;
	for(l+=n, r+=n; l<r; l>>=1, r>>=1)
	{
		if(l&1)
		{
			if(t[l].ff>qu.ff)
			{
				qu.ss=max(qu.ff, t[l].ss);
				qu.ff=t[l].ff;
			}
			else
			{
				qu.ss=max(qu.ss, t[l].ff);
			}

			l++;
		}
		if(r&1)
		{
			--r;

			if(t[r].ff>qu.ff)
			{
				qu.ss=max(qu.ff, t[r].ss);
				qu.ff=t[r].ff;
			}
			else
			{
				qu.ss=max(qu.ss, t[r].ff);
			}
		}
	}
	return qu;
}

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int ai, q, x, y;
	pii qu;
	char ch;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>ai;
		t[i+n]={ai, LLONG_MIN};
	}
	build();
	cin>>q;
	while(q--)
	{
		cin>>ch;
		if(ch=='U')
		{
			cin>>x>>y;
			update(x-1, y);
		}
		else
		{
			cin>>x>>y;
			qu=query(x-1, y);
			cout<<qu.ff+qu.ss<<"\n";
		}
	}

}