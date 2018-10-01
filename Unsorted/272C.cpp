#include<iostream>
#include<set>
#define int long long
using namespace std;

int32_t main()
{
	int n;
	cin>>n;
	int w[n];
	for(int i=0; i<n; ++i)
	{
		cin>>w[i];
	}

	int m;
	cin>>m;
	int L=0, hprev=0, hi, wi;
	for(int i=0; i<m; ++i)
	{	
		cin>>wi>>hi;

		L=max(L+hprev, w[wi-1]);
		hprev=hi;
		cout<<L<<endl;
	}
}