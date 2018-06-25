#include<iostream>
using namespace std;
#define ll long long

bool check(ll n, ll k)
{
	ll curr=n;
	ll count=0;
	while(curr)
	{
		count+=min(k,curr);
		curr-=min(k,curr);
		curr-=curr/10;
	}
	if(2*count>=n)
	{
		return 1;
	}
	else
		return 0;
}

int main()
{
	ll n;
	cin>>n;
	if(n<10)
	{
		cout<<1<<endl;
		return 0;
	}
	ll l=1, r=n, mid,k=n;
	ll candies=0;
	while(l<=r)
	{
		mid=(l+r)/2;
//		cout<<l<<" "<<mid<<" "<<r<<endl;
		bool b=check(n,mid);

		if(b)
		{
			r=mid-1;
			k=min(mid,k);
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<k<<endl;
}