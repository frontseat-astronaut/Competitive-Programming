#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ff  first
#define ss second
using namespace std;

int32_t main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	string c;
	bool done=0;
	for(int i=0; i<n-1; ++i)
	{
		if(s[i]>s[i+1] && !done)
		{
			done=1;
			continue;
		}
		c+=s[i];
	}
	if(done)
		c+=s.back();
	cout<<c<<endl;
}