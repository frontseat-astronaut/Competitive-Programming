#include<iostream>
#define m 998244353
#define int long long
using namespace std;

int32_t main()
{
	int N, K;
	cin>>N>>K;

	int a[N+1][K+5]={}, b[N+1][K+5]={};

	a[0][K]=1, b[0][K]=1;

	for(int n=1; n<=N; ++n)
	{
		for(int k=K; k>=1; --k)
		{
			a[n][k]=((a[n-1][k]+(2*b[n-1][k+1])%m)%m+a[n-1][k+1])%m;
			b[n][k]=((2*a[n-1][k])%m+(b[n-1][k+2]+b[n-1][k])%m)%m;
		}
	} 
	cout<<((2*a[N-1][1])%m+(2*b[N-1][2])%m)%m<<endl;
}