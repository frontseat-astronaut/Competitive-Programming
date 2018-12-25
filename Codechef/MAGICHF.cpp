#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, k, temp;
		cin>>n>>k;
		double ans;

		if(n==1)
		{
			ans=1;
		}
		else if(n==2)
		{
			ans=0.5;
		}
		else
		{
			int N=n;
			while(n>1 && k)
			{
				if(k==1 && n>2 && n==N)
				{
					if((n/2)&1 && (n-n/2)&1)
					{
						n=n/2+1;
						break;
					}
				}
				n=n-n/2;
				k--;
			}
			ans=(double)1/n;
		}
		printf("%.10f\n", ans);
	}
}