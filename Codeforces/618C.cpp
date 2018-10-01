#include<iostream>
#include<algorithm>
#include<climits>
#define int long long
using namespace std;
struct p
{
	double x,y,id;
}m;

int d(p a, p b)
{
	return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cmp(p a, p b)
{
	return d(a,m)<d(m,b);
}

bool collinear(p a, p b, p c)
{
	if((a.y-b.y)*(a.x-c.x)==(a.y-c.y)*(a.x-b.x))
		return 1;
	return 0;
}

int32_t main()
{
	int n, D, minD;
	cin>>n;
	p P[n];

	cin>>P[0].x>>P[0].y;
	P[0].id=1;
	minD=LLONG_MAX;
	for (int i = 1; i < n; ++i)
	{
		cin>>P[i].x>>P[i].y;
		P[i].id=i+1;
		D=d(P[0],P[i]);
		if(D<minD)
		{
			minD=D;
			swap(P[i],P[1]);
		}
	}

	m={(P[0].x+P[1].x)/2,(P[0].y+P[1].y)/2, -1};

	sort(P+2,P+n,cmp);

	cout<<P[0].id<<" "<<P[1].id<<" ";
	for(int i=2; i<n; ++i)
	{
		if(!collinear(P[0],P[1],P[i]))
		{
			cout<<P[i].id<<endl;
			break;
		}
	}
}
