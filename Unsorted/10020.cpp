#include<bits/stdc++.h>
using namespace std;

struct point
{
	int x, id;
};

struct line
{
	int L,R, id;
};

struct cmp
{
	bool operator() (const line& a, const line& b)
	{
		if(a.R==b.R)
			return a.id<b.id;
		return a.R<b.R;
	}
};

struct cmpans
{
	bool operator() (const line& a, const line& b)
	{
		if(a.L==b.L)
			return a.id<b.id;
		return a.L<b.L;
	}
};

bool cmpx(point a, point b)
{
	if(a.x==b.x)
		return a.id>b.id;
	return a.x<b.x;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int l,r,M;
		cin>>M;
		vector<point> P;
		vector<line> L;
		int n=0;
		while(1)
		{
			cin>>l>>r;
			if(l==0 && r==0)
				break;
			n++;
			P.push_back({l,n});
			P.push_back({r,-n});
			L.push_back({l,r, n});
		}
		sort(P.begin(), P.end(), cmpx);

		int x=0, i=0;
		bool flag=true;
		set <line, cmp> curr, ans;
		while(x<M)
		{
			while(P[i].x<=x && i<2*n)
			{
				if(P[i].id>0)
					curr.insert(L[P[i].id-1]);

				if(P[i].id<0)
					curr.erase(L[-P[i].id-1]);
				++i;
			}
			if(curr.empty())
			{
				flag=0;
				break;
			}
			auto it=curr.rbegin();
			ans.insert((*it));
			x=(*it).R;
		}
		if(flag)
		{
			cout<<ans.size()<<endl;

			for(auto l: ans)
			{
				cout<<l.L<<" "<<l.R<<endl;
			}
		}
		else
			cout<<0<<endl;

		if(T) cout<<endl;
	}
}