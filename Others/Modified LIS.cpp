#include<iostream>
#define MOD 1000000007
using namespace std;

int main()
{
    int N;
    cin>>N;
    int dp[N]={}, dpcnt[N]={};
    int a[N];
    int ns[2]={-1, -1};
    int maxm=0;
    for (int i = 0; i < N; ++i)
    {
    	cin>>a[i];
    	ns[(a[i]>0)]=i;
    }
    dp[N-1]=1;
    dpcnt[N-1]=1;

    for(int i=N-2; i>=0; --i)
    {
    	if(ns[!(a[i]>0)]>i)
    	    dp[i]=dp[ns[!(a[i]>0)]]+1;
    	else
    	    dp[i]=1;
    	ns[a[i]%2]=i;
    	dpcnt[i]=dpcnt[i-1];
    	if(dp[i]>maxm)
    	{
    		maxm=dp[i];
    		dpcnt[i]++;
    	}
    	else if(dp[i]==maxm)
    	{
    		dpcnt[i]++;
    	}
    }
    cout<<max<<endl;
}