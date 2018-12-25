#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k;
		cin>>k;
		bool a[7];
		int sum=0;
		for (int i = 0; i < 7; ++i)
		{
			cin>>a[i];
			sum+=a[i];
		}
		int ans=(k/sum)*7;
		int r=(k%sum);
		if(!r)
		{
			ans-=7;
			r=sum;
		}

		int minm=INT_MAX, tmp, cnt;
		for(int i=0, j; i<7; ++i)
		{
			j=i;
			tmp=r;
			cnt=0;
			while(tmp)
			{
				tmp-=a[(j)%7];
				j++;
				++cnt;
			}
			minm=min(minm, cnt);
		}
		cout<<ans+minm<<endl;
	}
}