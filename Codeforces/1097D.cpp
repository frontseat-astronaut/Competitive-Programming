#include<bits/stdc++.h>
#define int long long
using namespace std;
#define pii pair<int,int>
#define ff first
#define ss second

const int mod=1e9+7;

int powr(int a, int r)
{
	if(r==1)
		return a;
	int tmp=powr(a, r>>1);
	tmp=(tmp*tmp)%mod;
	if(r&1)
		tmp=(tmp*a)%mod;
	return tmp;
}

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n, K, cnt=0;
	cin>>n>>K;
	vector<pii>p;

	//uses the fact that a number n can have at most one prime factor greater than sqrt(n)
	for (int i = 2; i*i<=n; ++i)
	{
		if(n%i==0)
		{
			cnt=0;
			while(n%i==0)
			{
				cnt++;
				n/=i;
			}
			p.push_back({i, cnt});
		}
	}
	if(n>1) p.push_back({n, 1});
	int ip[100];
	for(int i=1; i<100; ++i)
	{
		ip[i]=powr(i, mod-2);
	}
	int ans=1;
	int np=p.size();
	vector<int>dp[np];
	for(int i=0; i<np; ++i)
	{
		dp[i].resize(p[i].ss+1);
		dp[i][p[i].ss]=1;
		for(int j=1; j<=K; ++j)
		{
			dp[i][p[i].ss]=(ip[p[i].ss+1]*dp[i][p[i].ss])%mod;
			int temp=dp[i][p[i].ss];
			for(int k=p[i].ss-1; k>=0; --k)
			{
				temp=(temp+((ip[k+1]*dp[i][k])%mod) )%mod;
				dp[i][k]=temp;
			}
		}
		int exp=0, temp=1; 
		for(int j=0; j<=p[i].ss; ++j)
		{
			exp=(exp + (dp[i][j]*temp)%mod)%mod;
			temp=(temp*(p[i].ff%mod))%mod;
		}
		ans=(ans*exp)%mod;
	}
	cout<<ans;
}