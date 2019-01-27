#include<bits/stdc++.h>
using namespace std;
struct pnt
{
	double x, y;
	bool operator<(pnt const &other) const
	{
		if(x!=other.x)
			return x<other.x;
		return y<other.y;
	}
};

double orient(pnt p, pnt q, pnt r)
{
	return ( (q.x*r.y-q.y*r.x) +(p.y*r.x-p.x*r.y) +(p.x*q.y-q.x*p.y) );
}

void convex_hull(vector<pnt>&a, vector<pnt>p, int n)
{
	if(p.size()<=1) return;

	sort(p.begin(), p.end());
	pnt p1=p[0], p2=p[n-1];

	vector<pnt>up, down;
	up.push_back(p1);
	for(int i=1; i<n; ++i)
	{
		if(i==n-1 || orient(p1, p[i], p2)<0)
		{
			while(up.size()>=2 && orient(up[up.size()-2], up[up.size()-1],p[i])>=0)
				up.pop_back();
			up.push_back(p[i]);
		}
	}
	up.pop_back();
	down.push_back(p2);
	for(int i=n-2; i>=0; --i)
	{
		if(i==0 || orient(p1, p[i], p2)>0)
		{
			while(down.size()>=2 && orient(down[down.size()-2], down[down.size()-1],p[i])>=0)
				down.pop_back();
			down.push_back(p[i]);
		}
	}
	down.pop_back();
	a=up;
	a.insert(a.end(), down.begin(), down.end());
}

int32_t main()
{
	vector<pnt>p;
	vector<pnt>ch;
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		double x, y;
		cin>>x>>y;
		p.push_back({x,y});
	}
	convex_hull(ch, p, n);
	for(auto x:ch)
		cout<<x.x<<" "<<x.y<<"\n";
}