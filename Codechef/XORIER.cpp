#include<iostream>
#include<map>
#define int long long
using namespace std;
int32_t main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;
		map<int,int>A;
		int odd=0, even=0;
		for(int i=0; i<N; ++i)
		{
			int a;
			cin>>a;
			A[a]++;
			if(a%2==0)
				even++;
			else
				odd++;
		}
		int ans=0;
		if(even>1)
			ans+=even*(even-1)/2;
		if(odd>1)
			ans+=odd*(odd-1)/2;
		int two=0;
		for(auto a:A)
		{
			if(a.second>1)
			{
				ans-=a.second*(a.second-1)/2;
			}
			int a_=a.first^2;
			if(A[a_])
			{
				two+=a.second*A[a_];
			}
		}
		two/=2;
		ans-=two;
		cout<<ans<<endl;
	}
}