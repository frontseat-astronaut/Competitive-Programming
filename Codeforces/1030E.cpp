#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	int n;
	cin>>n;
	int a[n]={}, ai;
	for (int i = 0; i < n; ++i)
	{
		cin>>ai;
		while(ai)
		{
			a[i]+=ai&1;
			ai>>=1;
		}
	}

}