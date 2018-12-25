#include<bits/stdc++.h>

using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	set<int>s;
	if(a[0]!=0)
	{
		cout<<1;
		return 0;
	}
	s.insert(0);
	int i;
	for(i=1; i<n; ++i)
	{
		if(!a[i]) continue;
		if(s.find(a[i]-1)==s.end())
		{
			cout<<i+1;
			return 0;
		}
		s.insert(a[i]);
	}
	cout<<-1;
}