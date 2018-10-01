#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int a[n];
	for(int i=0; i<n; ++i)
		cin>>a[i];

	sort(a,a+n);
	int i=0,j=0;
	int ans=0; 
	while(i<n && j<n)
	{
		while(a[i]>=a[j] && j<n) ++j;
		if(j<n) ++ans;
		++i; ++j;
	}
	cout<<ans<<endl;
}