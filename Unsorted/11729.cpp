#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

struct soldier
{
	int B, J;
};

bool cmp1(soldier a, soldier b)
{
	if( a.B==b.B )
		return 	a.J>b.J;
	return a.B<b.B;
}
bool cmp2(soldier a, soldier b)
{
	if(a.J==b.J)
	{
		return a.B<b.B;
	}
	return a.J>b.J;
}

int main()
{
	int N;
	int caseno=1;
	while(cin>>N)
	{
		if(!N) break;
		vector <soldier> LA, LB;
		for(int i=0; i<N; ++i)
		{
			soldier S;
			cin>>S.B>>S.J;

			if(S.B<S.J)
			{
				LA.push_back(S);
			}
			else
				LB.push_back(S);
		}
		sort(LA.begin(), LA.end(), cmp1);
		sort(LB.begin(), LB.end(), cmp2);

		int ts=0, tg=0;
		for(auto S: LA)
		{
			ts+=S.B;
			tg=max(ts, tg)+S.J;
		}
		for(auto S: LB)
		{
			ts+=S.B;
			tg=max(ts, tg)+S.J;
		}
		cout<<"Case "<<caseno++<<": "<<tg<<endl;
	}
}