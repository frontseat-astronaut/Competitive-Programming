#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	int sum=0;
	for(int i=0; i<n; ++i)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(n==1) 
	{
		cout<<-1<<endl;
		return 0;
	}
	bool flag=false;
	int s=0;
	int i;
	for( i=0; i<n; ++i)
	{
		s+=a[i];
		if(2*s!=sum)
		{
			flag=true;
			break;
		}
	}
	if(flag && i<n-1)
	{
		cout<<i+1<<endl;
		for(int j=0; j<=i; ++j)
			cout<<j+1<<" ";
		cout<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
}