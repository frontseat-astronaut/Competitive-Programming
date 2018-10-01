#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, d, r;
	while(1)
	{
		cin>>n>>d>>r;
		if(n==0) break;

		int day[n], night[n];
		for(int i=0; i<n; ++i)
		{
			cin>>day[i];
		}
		for(int i=0; i<n; ++i)
		{
			cin>>night[i];
		}
		sort(day, day+n), sort(night, night+n);
		long long ans=0;
		for(int i=0; i<n; ++i)
		{
			ans+=max(r*(day[i]+night[n-1-i]-d),0);
		}
		cout<<ans<<endl;
	}
}