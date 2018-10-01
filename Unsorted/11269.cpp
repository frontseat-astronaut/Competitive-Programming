#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

struct prob
{
	int S, G;
};

int signum(int x)
{
	if(x>0) return 1;
	else if (!x) return 0;
	else return -1;
}

bool cmp2(prob a, prob b)
{
	return min(a.S,b.G)>min(b.S, a.G);
}

int main()
{
	int N;
	while(cin>>N)
	{
		vector <prob> P(N);
		for(int i=0; i<N; ++i)
		{
			cin>>P[i].S;
		}
		for(int i=0; i<N; ++i)
		{
			cin>>P[i].G;
		}
		sort(P.begin(), P.end(), cmp2);
		int ts=0, tg=0;
		while(P.size())
		{
			ts+=P[N-1].S;
			tg=max(ts, tg)+P[N-1].G;

			P.pop_back();
			N--;
		}
		cout<<max(tg,ts)<<endl;
	}
}