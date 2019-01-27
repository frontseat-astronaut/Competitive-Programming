#include<bits/stdc++.h>
using namespace std;
#define int long long
int m=998244353 ;
int fact[1000001];
int invfact[1000001];
int powr(int a, int r)
{
	if(r==1)
		return a%m;
	int tmp=powr(a, r/2);
	tmp=(tmp*tmp)%m;
	if(r&1)
	{
		tmp=(tmp*a)%m;
	}
//  	cout<<tmp<<' ';
	return tmp;
}
int C(int n, int r)
{
	int tmp=(fact[n]*invfact[r])%m;
	tmp=(tmp*invfact[n-r])%m;
	return tmp;
}
int32_t main()
{
	int n;
	cin>>n;
	fact[0]=1;
	invfact[0]=1;
	for(int i=1; i<=n; ++i)
	{
		fact[i]=(fact[i-1]*i)%m;
		invfact[i]=powr(fact[i],m-2);
	}
	int ans=0;
	for(int i=0; i<n; ++i)
	{
		if(i)
			ans=(ans+ ( ((C(n,n-i)*((fact[n-i]-1)%m))%m) * fact[i] )%m )%m;	
		else
			ans=fact[n];
		// cout<<ans<<" ";
	}
	cout<<ans;
}