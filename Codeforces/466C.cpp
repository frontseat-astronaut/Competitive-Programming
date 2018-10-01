#include<iostream>
#include<unordered_map>
#define ll long long
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	ll a[n], sum=0;
	unordered_map<ll,int>m;
	for(int i=0; i<n; ++i)
	{
		cin>>a[i];
		sum+=a[i];
		a[i]=sum;
		m[sum]++;
	}
	if(a[n-1]%3)
	{
		cout<<0<<endl;
		return 0;
	}
	sum=a[n-1]/3;
	ll ans=0;
	for(int i=0; i<n; ++i)
	{
		m[a[i]]--;
		if(a[i]!=sum) 
		{
			continue;
		}	
		int x2=m[2*sum];
		if(x2>0)
		{
			if(a[n-1]==2*sum)
				ans+=x2-1;
			else ans+=x2;
		}
	}
	cout<<ans<<endl;
}
