#include<bits\stdc++.h>
#define int long long
using namespace std;

int32_t main()	
{
	int t;
	cin>>t;
	while(t--)
	{
		int a;
		cin>>a;
		int cnt=1;
		while(a)
		{
			cnt<<=(a&1);
			a>>=1;
		}
		cout<<cnt<<endl;
	}
}