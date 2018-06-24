#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	float sum=0;
	for(int i=0; i<n; ++i)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	sort(arr,arr+n);

	int  i=0;
	while(sum<4.5*n)
	{
		sum=sum+5-arr[i];
		arr[i]=5;
		++i;
	}
	cout<<i<<endl;
}