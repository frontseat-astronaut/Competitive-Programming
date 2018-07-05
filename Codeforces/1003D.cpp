#include<iostream>
#include<math.h>
#define ll long long
using namespace std;

int main()
{
	ll n,q;
	cin>>n>>q;
	int d[35]={0};
	for(ll i=0; i<n; ++i)
	{
		ll a;
		cin>>a;
		d[(ll)log2(a)]++;
	}
//	cout<<d[2]<<endl;
	while(q--)
	{
		ll b;
		cin>>b;
		
		int temp[35];
		for(int i=0; i<35; ++i)
			temp[i]=d[i];

		ll N=log2(b);
		bool flag=true;
		ll c=0;
		for(ll i=N; i>=0; --i)
		{
			if(b&(1<<i))
			{
				ll req=1, k;
				for( k=i; k>=0 ; --k, req*=2)
				{
					if(temp[k]>=0)
					{
						int init = req;
						req=max((ll)0,req-temp[k]);
						temp[k]-=init-req;
						c+=init-req;
					}
					if(req==0) break;
				}
				if(req)
				{
					flag=false;
					break;
				}
			}
		}
		if(flag)
			cout<<c<<endl;
		else
			cout<<-1<<endl;
	}
}