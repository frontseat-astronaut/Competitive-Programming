#include<iostream>
#include<math.h>
#define int long long
using namespace std;

int32_t main()
{
	int S;
	while(cin>>S)
	{
		int ans=0;
		if(S==0)
		{
			cout<<0<<endl;
			continue;
		}
		while(S>1)
		{
//			cout<<S<<endl;
			if(S%2==1)
			{
				ans++;
				int temp=S-1, i=0;
				while(temp>0 && temp%2==0)
				{
					temp/=2;
					++i;
				}
				temp=S+1; 
				int j=0;
				while(temp>0 && temp%2==0)
				{
					temp/=2;
					++j;
				}
				if(S<=3)
					S--;
				else if(i>j)
					S--;
				else S++;
				continue;
			}

			S/=2;
			ans++;
		}
		cout<<ans+1<<endl;
	}
}