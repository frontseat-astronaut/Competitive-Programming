#include<iostream>
#define int long long
using namespace std;

int32_t main()
{
	int32_t C;
	cin>>C;
	while(C--)
	{
		int P,Q;
		cin>>P>>Q;

		if(P%2==1)
		{
			if(P+1<=2*Q)
			{
				int ans=0, N=(P-1)/2;
				while(N--)
				{
					ans*=8;
					ans+=6;
				}
				ans*=2;
				ans++;
				cout<<ans<<endl;
			}
			else
			{
				int N=P+Q, i=0, ans=0;
				while(i<Q)
				{
					ans*=8;
					ans+=5;
					N-=3;
					++i;
				}
				while(N--)
				{
					ans*=2;
					ans++;
				}
				cout<<ans<<endl;

			}
		}
		else
		{
			if(P<=2*Q)
			{
				int ans=0, N=P/2;
				while(N--)
				{
					ans*=8;
					ans+=5;
				}
				cout<<ans<<endl;
			}
			else
			{
				int N=P+Q, i=0, ans=0;
				while(i<Q)
				{
					ans*=8;
					ans+=5;
					N-=3;
					++i;
				}
				while(N--)
				{
					ans*=2;
					ans++;
				}
				cout<<ans<<endl;

			}
		}
	}
}