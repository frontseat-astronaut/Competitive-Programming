#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<stdio.h>

using namespace std;

struct point
{
	double x,y;
};

vector<point> P;
double T;
double sin60=0.8660254037844386;

int sign(double d)
{
	if(d<T*T*4)
		return -1;
	else if(fabs(d-4*T*T)<10e-8)
		return 0;
	else
		return 1;
}

bool cmp(point a, point b)
{
	if(fabs(a.x-b.x)<10e-8)
	{
		return a.y<b.y;
	}
	else
		return a.x<b.x;
}

void fractal(point a, point b)
{
	point diff={b.x-a.x, b.y-a.y};
	point c={a.x+0.25*diff.x,a.y+0.25*diff.y};
	point d={a.x+0.75*diff.x,a.y+0.75*diff.y};
	point e={c.x+0.5*(d.x-c.x)-sin60*(d.y-c.y),c.y+0.5*(d.y-c.y)+sin60*(d.x-c.x)};
	double d_2=(diff.x*diff.x + diff.y*diff.y);

	if(sign(d_2)>=0)
	{
		P.push_back(c);
		P.push_back(d);
		P.push_back(e);
		fractal(c,e);
		fractal(e,d);
	}
}

int main()
{
	double x1,x2,y1,y2;
	int caseno=1;
	while(true)
	{
		cin>>x1>>y1>>x2>>y2>>T;
		if(T<1)
			break;
		P.clear();
		P.push_back({x1,y1});
		P.push_back({x2,y2});
		fractal({x1,y1},{x2,y2});

		sort(P.begin(), P.end(), cmp);

		printf("Case %d:\n",caseno++);
		printf("%d\n", P.size());
		for(auto p: P)
		{
			printf("%.5f %.5f\n",p.x,p.y);
		}
	}
}