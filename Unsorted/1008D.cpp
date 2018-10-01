#include<bits/stdc++.h>
using namespace std;

struct triplet
{
	int x,y,z;
};

map<int,set<int>>f;

struct cmp {
    bool operator() (const triplet& a, const triplet& b) const {
    	if(a.x==b.x)
    	{
    		if(a.y==b.y)
    		{
    			return a.z<b.z;
    		}
    		return a.y<b.y;
    	}
        return a.x<b.x;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int A,B,C;
		cin>>A>>B>>C;

		set<triplet,cmp>ans;
		vector<pair>temp;
		set<int>a,b,c;

		for(int i=1; i*i<=max(max(A,B),C); ++i)
		{
			if(A%i==0)
			{
				a.insert(i);
				a.insert(A/i);
			}
			if(B%i==0)
			{
				b.insert(i);
				b.insert(B/i);
			}
			if(C%i==0)
			{
				c.insert(i);
				c.insert(C/i);
			}
		}

		for(auto ia=a.begin(); ia!=a.end(); ++ia)
		{
			for(auto ib=b.begin(); ib!=b.end(); ++ib)
			{
				for(auto ic=c.begin(); ic!=c.end(); ++ic)
				{
					int v[3]={(*ia),(*ib),(*ic)};
					sort(v, v+3);
					ans.insert({v[0],v[1],v[2]});
				}
			}
		}
		cout<<ans.size()<<endl;
	}
}