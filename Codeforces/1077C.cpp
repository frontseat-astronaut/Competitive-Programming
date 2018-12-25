#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int32_t main()
{
	int n;
	cin>>n;
	int a[n], sum=0;
	map<int,int>m;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		sum+=a[i];
		m[a[i]]++;
	}
	int s;
	vector<int>ans;
	for (int i = 0; i < n; ++i)
	{
		s=sum-a[i];
		if(s&1) continue;
		if(a[i]==s>>1)
		{
			if(m[s>>1]>1)
				ans.push_back(i);
		}
		else if (m[s>>1]>0)
			ans.push_back(i);
	}
	cout<<ans.size()<<endl;
	for(auto an:ans)
		cout<<an+1<<" ";
}