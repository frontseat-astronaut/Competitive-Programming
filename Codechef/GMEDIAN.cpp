#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
int m=1000000007;
using namespace std;

int fact[1001];
int invfact[1001];

int power(int a, int n)
{
	if(n==0)
		return 1;
	int t=power(a,n/2);
	t=(t*t)%m;
	if(n&1)
		t=(t*a)%m;
	return t;
}

int C(int n, int r)
{
	if(n<r)
		return 0;
	if(!r||!(n-r))
		return 1;
	int c=(invfact[r]*invfact[n-r])%m;
	c=(c*fact[n])%m;
	return c;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	fact[0]=1, invfact[0]=1;
	for (int i = 1; i < 1001; ++i)
	{
		fact[i]=(fact[i-1]*i)%m;
		invfact[i]=power(fact[i],m-2);
	}

	int t;
	cin>>t;
	while(t--)
	{
		int N, n=0, ans, i, j;
		cin>>N;

		int A[N];
		vector<int>a;

		for(int i = 0; i < N; ++i)
		{
			cin>>A[i];
		}
		sort(A,A+N);

		ans=0;

		i=0;
		while(i<N)
		{
			j=i;
			while(A[j]==A[i] && j<N)
			{
				++j;
			}
			j--;

			a.pb(j-i+1);
			i=j+1;
		}
		n=a.size();
		if(n==N)
		{
			for(int i=0; i<n; ++i)
			{
				for(int k=0; k<=min(i, n-1-i); ++k)
				{
					ans=(ans+(C(i,k)*C(n-1-i,k))%m)%m;
				}
			}
			cout<<ans<<endl;
			continue;
		}
		int pref[n]={}, sum=0;
		for(int i=0; i<n; ++i)
		{
			pref[i]=sum;
			sum+=a[i];
		}
		int suff[n]={};
		sum=0;
		for(int i=n-1; i>=0; --i)
		{
			suff[i]=sum;
			sum+=a[i];
		}
		for(int i=0; i<n; ++i)
		{
			int temp[a[i]+1]={};
			sum=0;
			for(int k=0; k<=a[i]; ++k)
			{
				sum=(sum+C(a[i],k))%m;
				temp[k]=sum;
			}

			int t;
			for(int l=0; l<=pref[i]; ++l)
			{
				for(int r=0; r<=suff[i]; ++r)
				{
					t=0;
					int diff=fabs(r-l);
					if(diff+1>a[i])
						continue;
					t=((t+temp[a[i]])%m+(-temp[diff]+m)%m)%m;
					t=(t*C(pref[i],l))%m;
					t=(t*C(suff[i],r))%m;
					ans=(ans+t)%m;
				}
			}
		}
		cout<<ans<<endl;

	}
}