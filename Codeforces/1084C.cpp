#include<bits/stdc++.h>
#define int long long
using namespace std;
int m=1e9+7;

int32_t main()
{
	string s;
	cin>>s;
	int n=s.length();

	vector<int>a;
	int i=0, cnta=0;
	while(i<n)
	{
		if(s[i]=='a')
		{
			++cnta;
		}
		if(s[i]=='b')
		{
			if(cnta)
				a.push_back(cnta);
			cnta=0;
		}
		++i;
	}
	if(cnta)
		a.push_back(cnta);
	n=a.size();
	// for(auto ai:a)
	// 	cout<<ai<<" ";
	if(!n)
	{
		cout<<0;
		return 0;
	}

	int ans=0;
	for(int i=n-1; i>=0; --i)
	{
		ans=((a[i]+(a[i]*ans)%m)%m + ans)%m;
	}
	cout<<ans;
}
