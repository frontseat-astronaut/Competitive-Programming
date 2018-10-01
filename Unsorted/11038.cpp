#include<iostream>
#include<vector>
#include<math.h>
#define int long long
using namespace std;

int32_t main()
{
	while(1)
	{
		int m,n;
		cin>>m>>n;
		if(m<0)
			break;

		int ten=10, one=1;
		int ans=0;
		while(ten<=n)
		{
			int init=ans;

			if(n/one==m/one)
			{
//				cout<<ans-init<<endl;
				break;
			}

			else
			{
				ans+=(n/ten-ceil((double)max(m,ten)/ten))*one+1;
				ans+=min(n-(n/ten)*ten,one-1);
				if(m%ten!=0 && m>=ten)
					ans+=max((int)0,(m/ten)*ten+one-m);
			}
			ten*=10;
			one*=10;

//			cout<<ans-init<<endl;
		}
		while(n/one)
		{
			if((n/one)%10==0)
			{
				ans+=n-m+1;
			}
			one*=10;
		}
		if(m==0) ans++;

		cout<<ans<<endl;
	}
}