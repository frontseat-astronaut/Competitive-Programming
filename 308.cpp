#include<bits/stdc++.h>
using namespace std;

struct point
{
	float x,y;
};

struct line
{
	float x1,x2,y1,y2;
};

int main()
{
	int N;
	while(true)
	{
		cin>>N; 
		if(!N) break;

		map <point, int> P;
		vector <line> L;

		for(int i=0; i<N; ++i)
		{
			float x1,x2,y2,y1;
			cin>>x1>>x2>>y1>>y2;

			P[{x1,y1}]++;
			P[{x2,y2}]++;

			if(x1==x2)
			{
				L.push_back({x1,x2,y1,y2});
			}
		}

	}
}