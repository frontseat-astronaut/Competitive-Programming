#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
	int n;
	cin>>n;
	set<int>mem[n+1];
	int ai1, ai2;
	for (int i = 1; i <= n; ++i)
	{
		cin>>ai1>>ai2;
		mem[i].insert(ai1);
		mem[i].insert(ai2); 
	}
	vector<int>P;
	P.push_back(1);
	auto it=mem[P[0]].begin();
	ai1=(*it);
	it++;
	ai2=(*it);

	if(mem[ai1].find(ai2)!=mem[ai1].end())
	{
		P.push_back(ai1);
	}
	else
	{
		P.push_back(ai2);
	}
	for( int i=1; i<n-1; ++i)
	{
		for(auto x: mem[P[i-1]])
		{
			if(x!=P[i])
			{
				P.push_back(x);
				break;
			}
		}
	}
	for(auto x:P)
		cout<<x<<' ';
}