#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pii pair<int,int>
using namespace std;

int32_t main()
{
	string c;
	cin>>c;
	string h[5];
	for(int i=0; i<5; ++i)
	{
		cin>>h[i];
		if(h[i][0]==c[0] || h[i][1]==c[1])
		{
			cout<<"YES";
			exit(0);
		}
	}
	cout<<"NO";
}