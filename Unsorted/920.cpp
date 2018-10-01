#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

struct point
{
	int X, Y;
};

bool cmp(point a, point b)
{
	return a.X<b.X;
}

int main()
{
	int C;
	cin>>C;
	while(C--)
	{
		int N;
		cin>>N;
		vector<point>P(N);
		for(int i=0; i<N; ++i)
		{
			cin>>P[i].X>>P[i].Y;
		}
		sort(P.begin(), P.end(), cmp);

		if(N==1) 
		{
			cout<<"0.00"<<endl;
			continue;
		}

		int y=0;
		double x=P[N-1].X;
		double ans=0;
		int i=N-2;
		while(i>=0)
		{
//			cout<<i<<endl;
			ans+=sqrt((P[i].X-x)*(P[i].X-x)+(P[i].Y-y)*(P[i].Y-y));
			y=P[i].Y;
			while(i>=0 && P[i].Y<=y)
				--i;
			if(i<0) break;
			x=((double)(P[i].X-P[i+1].X)/(P[i].Y-P[i+1].Y))*(y-P[i].Y)+P[i].X;			
		}
		printf("%.2lf\n",ans);

	}
}