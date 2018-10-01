#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define int long long
using namespace std;

struct marker
{
	int x, id;
	int l,r;
};

struct station
{
	int id, r;
};

bool cmpx(marker a, marker b)
{
	return a.x<b.x;
}

struct cmp
{
	bool operator()(const station &a, const station &b) const
	{
		return a.r<b.r;
	}
};

int32_t main()
{
	while(1)
	{
		int L, G;
		cin>>L>>G;
		if(L==0 && G==0) break;

		vector<marker>M;
		for(int i=0; i<G; ++i)
		{
			int x, r;
			cin>>x>>r;

			M.push_back({x-r,i+1,x-r,x+r});
			M.push_back({x+r,-(i+1), x-r, x+r});
		}
		sort(M.begin(), M.end(), cmpx);
		int x=0, i=0;
		set <station, cmp> curr;
		bool flag=1;
		int ans=0;
		while(x<L)
		{
			while(i<2*G && M[i].x<=x)
			{
				if(M[i].id<0)
				{
					curr.erase({-M[i].id,M[i].r});
				}
				else
					curr.insert({M[i].id,M[i].r});
				++i;
			}
			if(curr.empty())
			{
				flag=false;
				break;
			}

			auto it=curr.rbegin();
			x=(*it).r;
			curr.erase((*it));
			++ans;
		}
		if(flag)
			cout<<G-ans<<endl;
		else
			cout<<-1<<endl;
	}
}