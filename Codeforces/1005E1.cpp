#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;

	int p[n];
	int mi;
	for(int i=0; i<n; ++i)
	{
		cin>>p[i];
		if(p[i]==m)
		{
			p[i]=0;
			mi=i;
		}
		else if(p[i]>m) p[i]=1;
		else p[i]=-1;
	}

	long long ans=0; 
	long long sum=0;
	unordered_map <long long,int> M;
	for(int i=0; i<mi; ++i)
	{
		sum+=p[i];
		M[sum]++;
	}
	for(int i=mi; i<n; ++i)
	{
		sum+=p[i];
		if(sum==0)
			ans++;
		if(sum==1)
			ans++;
		ans+=M[sum-1];
		ans+=M[sum];
	}
	cout<<ans<<endl;
}