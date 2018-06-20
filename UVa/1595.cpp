#include<bits/stdc++.h>
using namespace std;

struct point 
{
	long long x,y;
};
bool cmp1(point a, point b)
{
	if(a.x==b.x)
	{
		return a.y<b.y;
	}
	return a.x<b.x;
}
bool cmp2(point a, point b)
{
	if(a.x==b.x)
	{
		return a.y>b.y;
	}
	return a.x<b.x;
}
bool cmp(point a, point b)
{
	return a.x<b.x;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;

		vector <point> P;
		long long centre=0;

		for(int i=0; i<N; ++i)
		{
			long long x,y;
			cin>>x>>y;
			centre+=x;
			P.push_back({x,y}); 
		}

		sort(P.begin(), P.end(), cmp);
		sort(P.begin(), P.begin()+N/2, cmp1);
		sort(P.begin()+N/2, P.end(), cmp2);
/*
		for(auto p:P)
			cout<<p.x<<"|"<<p.y<<endl;
*/		
		bool flag=1;
		for(int i=0, j=N-1; i<=j; ++i,--j)
		{
			if( (P[i].x+P[j].x)*N/2 != centre)
			{
				flag=0;
				break;
			}
			if(P[i].x*N==centre)
			{
				break;
			}
			if(P[i].y!=P[j].y)
			{
				flag=false;
				break;
			}
		}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}