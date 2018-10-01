#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

struct island
{
	int x, y;
};

bool cmpi(island a, island b)
{
	if(a.x==b.x)
	{
		return a.y>b.y;
	}
	return a.x<b.x;
}

int main()
{
	int caseno=1;
	while(1)
	{
		int d, n;
		cin>>n>>d;

		if(n==0 && d==0) break;

		vector<island>I;
		bool flag=1;
		for(int i=0; i<n; ++i)
		{
			int x,y;
			cin>>x>>y;
			if(y>d)
			{
				flag =0;
			}
			I.push_back({x,y});
		}
		if(!flag)
		{
			cout<<"Case "<<caseno++<<": "<<-1<<endl;
			continue;
		}
		sort(I.begin(), I.end(), cmpi);

		vector<int>interv;
		for(int i=0; i<=d; ++i )
		{
			interv.push_back((int)2*sqrt(d*d-i*i) + 1);
		}

		double c;
		int i=0;
		int ans=0;
		while(i<n)
		{
			c=I[i].x+sqrt(d*d-I[i].y*I[i].y);
			while(i<n)
			{
				if((I[i].x-c)*(I[i].x-c)+I[i].y*I[i].y<d*d || fabs((I[i].x-c)*(I[i].x-c)+I[i].y*I[i].y-d*d)<0.0000001)
				{
					++i;
					continue;
				}
				if(I[i].x>c)
				{
					break;
				}
				c=I[i].x+sqrt(d*d-I[i].y*I[i].y);
				++i;
			}
			ans++; 
		}
		cout<<"Case "<<caseno++<<": "<<ans<<endl;
	}
}