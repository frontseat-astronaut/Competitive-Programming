#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	vector<int>p;
	int cnt=0;
	vector<bool> isprime(1000001, 1);
	int i;
	isprime[0]=0;
	isprime[1]=0;
	for(i=2; i<=1000001; ++i)
	{
		if(isprime[i])
		{
			p.push_back(i);
			cnt++;
			for(int j=i; i*j<=1000001; ++j)
			{
				isprime[j*i]=0;
			}
		}
	}

	int n, caseno=1;
	while(cin>>n)
	{
		if(!n)
			break;
		if(n==1 || n==2)
		{
			printf("Case %d: %d\n",caseno++, 0);
			continue;
		}
		int ans=0;
		int l, r, m;
		for (int i = 0; i < cnt; ++i)
		{
			if(p[i]>=n)
				break;
			l=0, r=i-1, m=-1;
			while(l<=r)
			{
				m=(l+r)/2;
				if(p[m]+p[i]<=n)
				{
					l=m+1;
				}
				else
					r=m-1;
			}
			if(m==-1)
				continue;
			if(p[m]+p[i]<=n)
				ans+=m+1;
			else
				ans+=m;
//			cout<<p[i]<<" "<<ans<<endl;
		}
		printf("Case %lld: %lld\n",caseno++, ans);
	}

}