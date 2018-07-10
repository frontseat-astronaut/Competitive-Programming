#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; ++i)
	{
		cin>>a[i];
	}
	int k=-1;
	int s[n]={0};
	for(int i=0; i<n; ++i, s[k]++)
	{
		if(a[i]==1)
		{
			++k;
			continue;
		}
	}
	cout<<k+1<<endl;
	for(int i=0; i<k+1; ++i)
		cout<<s[i]<<" ";
	cout<<endl;
}