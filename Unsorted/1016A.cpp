#include<iostream>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;

	int a[n];
	for(int i=0; i<n; ++i)
		cin>>a[i];
	int curr=0;
	for(int i=0; i<n; ++i)
	{
		int t=(a[i]+curr)/m;
		cout<<t<<" ";
		curr=(a[i]+curr)%m;
	}
}