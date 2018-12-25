#include<bits/stdc++.h>
#define pdd pair<double, double>
#define x first
#define y second
using namespace std;

int n;
pdd p[100001];

double check(double c)
{
	double maxm=0;
	for (int i = 0; i < n; ++i)
	{
		maxm=max(maxm, fabs(((p[i].x-c)*(p[i].x-c)+p[i].y*p[i].y)/(2*p[i].y)) );
	}
	return maxm;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	double l=DBL_MAX, r=DBL_MIN, mid1, mid2;
	double Rl, Rr;
	int iter;
	cin>>n;

	int sign=-1;
	for (int i = 0; i < n; ++i)
	{
		cin>>p[i].x>>p[i].y;
		r=max(r, p[i].x);
		l=min(l, p[i].x);
		if(sign!=-1 && sign!=(p[i].y>0))
		{
			cout<<-1<<endl;
			return 0;
		}
		sign=(p[i].y>0);
	}
	l-=1, r+=1;
	iter=100;
	while(iter--)
	{
		mid1=(2*l+r)/3;
		mid2=(l+2*r)/3;
		Rl=check(mid1);
		Rr=check(mid2);
		if(Rl<Rr)
		{
			r=mid2;
		}
		else 
			l=mid1;
	}
	printf("%.6lf\n",min(Rl,Rr));
}