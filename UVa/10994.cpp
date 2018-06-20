#include<iostream>
#include<math.h>
#define ll long long
using namespace std;

int main()
{
	ll p,q;
	while(true)
	{
		cin>>p>>q;
		if(p<0) break;
		ll ten=10, one=1 ;
		ll S=0;
		while(true)
		{
			ll i= ceil( (double)p/one )*one;
			ll j= ( q/one )*one;

			if( q/ten == p/ten )
			{
				for( ; i<=q; i+=one)
				{
					S+=(i/one)%10;
				}
				break;
			}

			for( ; (i/one)%10!=0; i+=one )
				S+=(i/one)%10;

			S+=( (j/one)%10 )*( (j/one)%10 + 1 )/2;

			ll l=ceil( (double)p/ten )*ten;
			ll r=( q/ten )*ten;

			S+=((r-l)/ten)*45;

			ten*=10; one*=10;
		}
		cout<<S<<endl;
	}
}