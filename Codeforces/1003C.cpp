#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int k;
	cin>>k;

	int a[n];
	for(int i=0; i<n; ++i)
		cin>>a[i];
	int maxavgn=0, maxavgd=1;
	int l=k;
	while(l<=n)
	{
		int max=0, sum=0;
		for(int i=0; i<l; ++i)
			sum+=a[i];
		if(sum>max)
			max=sum;
		for(int i=1; i<=n-l; ++i)
		{
			sum+=-a[i-1]+a[i+l-1];
			if(sum>max)
				max=sum;
		}
		if((long long)maxavgn*l<(long long)max*maxavgd)
		{
			maxavgn=max;
			maxavgd=l;
		}
		++l;
	}
	printf("%.7f\n",(float)maxavgn/maxavgd);
}