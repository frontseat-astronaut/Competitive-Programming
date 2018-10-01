#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	int cnt=0;
	for(int i=0; i<n; ++i)
	{
		cin>>a[i];
		if(a[i]<0)
			++cnt;
	}
	if(n==1)
	{
		cout<<a[0]<<endl;
		return 0;
	}
	sort(a,a+n);
	long long sum=-a[0];
	int i=1;
	while(i<min(cnt,n-1))
	{
		sum-=a[i];
		++i;
	}
	while(i<n)
	{
		sum+=a[i];
		++i;
	}
	cout<<sum<<endl;
}