#include<iostream>
#include<math.h>
using namespace std;

long long n,h;

long long DP(long long i, long long t, long long f[], long long d[], long long T[], long long dp[][25], long long ansdp[][25])
{
	if(t<0)
		return 0;
	if(i>=n) 
		return 0;
	if(dp[t][i]!=-1)
		return dp[t][i];

	long long ti=t, sum=0, k=f[i];
	long long maxm=0, maxt;
	while(ti>=0)
	{
		long long next = DP(i+1, ti-T[i], f, d, T, dp, ansdp) + sum ;
		if(next>=maxm)
		{
			maxm=next;
			maxt=t-ti;
		}
		ti--;
		sum+=max(k,(long long)0);
		k-=d[i];
	}
	dp[t][i]=maxm;
	ansdp[t][i]=maxt;
	return dp[t][i];
}

int main()
{
	long long caseno=1;
	while(cin>>n>>h)
	{
		if(!n) break;
		if((caseno++)!=1) cout<<endl;
		long long f[n], d[n], T[n-1];
		for(long long i=0; i<n; ++i)
			cin>>f[i];
		for(long long i=0; i<n; ++i)
			cin>>d[i];
		for(long long i=0; i<n-1; ++i)
			cin>>T[i];
		
		//dp!
		long long dp[h*12+1][25];
		long long ansdp[h*12+1][25]={};

		for(long long i=0; i<n-1; ++i)
		{
			dp[0][i]=0;
			for(long long t=1; t<=h*12; ++t)
			{
				dp[t][i]=-1;
			}
		}
		for(long long t=0, k=f[n-1], sum=0; t<=h*12; ++t, k-=d[n-1])
		{
			dp[t][n-1]=sum;
			sum+=max(k,(long long)0);
			if(d[n-1]==0) ansdp[t][n-1]=t;
			else ansdp[t][n-1]=min((long long)ceil((double)f[n-1]/d[n-1]),t);
		}
		long long ans=DP(0,h*12,f,d,T,dp, ansdp);
		long long time=h*12;
/*
		if(caseno!=306) continue;
		cout<<"case :"<<caseno<<endl;
		cout<<n<<" "<<h<<endl;
		for(int i=0; i<n; ++i)
			cout<<f[i]<<" ";
		cout<<endl;
		for(int i=0; i<n; ++i)
			cout<<d[i]<<" ";
		cout<<endl;
		for(int i=0; i<n-1; ++i)
			cout<<T[i]<<" ";
		cout<<endl;
*/

		for(long long i=0; i<n; ++i)
		{
			if(time>=0&&time<=h*12)
			{
				cout<<ansdp[time][i]*5;
//				cout<<" time: "<<time<<" ";
				time-=ansdp[time][i]+T[i];
			}
			else cout<<0;
			if(i<n-1) cout<<", ";
			else cout<<endl;
		}
		cout<<"Number of fish expected: "<<ans<<endl;
/*
		for(int t=0; t<=h*12; ++t)
		{
			for(int i=0; i<n; ++i)
			{
				cout<<dp[t][i]<<" ";
			}
			cout<<"\t\t";
			for(int i=0; i<n; ++i)
				cout<<ansdp[t][i]<<" ";
			cout<<endl;
		}
*/
	}
}