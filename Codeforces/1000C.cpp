#include<iostream>
using namespace std;

int main()
{
	int n, M;
	cin>>n>>M;

	int a[n];
	for(int i=0; i<n; ++i)
	{
		cin>>a[i];
	}

	int diff[n+1];
	diff[0]=a[0];
	int sign=-1;
	int maxm=diff[0];
	for(int i=1; i<n; ++i)
	{
		diff[i]=sign*(a[i]-a[i-1]);
		if(sign>0)
			maxm+=diff[i];
		sign*=-1;
	}
	diff[n]=sign*(M-a[n-1]);
	if(sign>0)
		maxm+=diff[n];

	int sump=0, sumn=0;
//	cout<<maxm<<endl;
//	for(int i=0; i<n+1; ++i)
//		cout<<diff[i]<<" ";
//	cout<<endl;
	int temp = maxm;
	for(int i=n; i>=0; i--)
	{
		if(diff[i]<-1)
		{
			int sum=temp-sump+sumn-diff[i]-1;
//			cout<<sum<<endl;
			if(sum>maxm)
				maxm=sum;
		}
		if(diff[i]>0) 
		{
			sump+=diff[i];
		}
		else
			sumn-=diff[i];

	}
	cout<<maxm<<endl;
}