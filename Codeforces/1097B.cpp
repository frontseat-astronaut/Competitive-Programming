#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pii pair<int,int>
using namespace std;

	int n;
	int a[15];
bool f(int i, int s)
{
	if(i==n)
	{
		if(!s)
			return 1;
		else
			return 0;
	}
	if(f(i+1, (s+a[i])%360))
		return 1;
	if(f(i+1, (s-a[i]+360)%360))
		return 1;
	return 0;
}

int32_t main()
{
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	if(f(0, 0))
		cout<<"YES";
	else
		cout<<"NO";

}