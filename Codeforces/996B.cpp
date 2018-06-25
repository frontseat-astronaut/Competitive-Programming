#include<iostream>
#include<math.h>
#define limit 9223372036854775807 
using namespace std;
int main()
{
	int n;
	cin>>n;

	int a[n];
	for(int i=0; i<n; ++i) cin>>a[i];

	long long min=limit;
	int min_k;
	for(int i=0;i<n; ++i)
	{
		int x=ceil((float)(a[i]-i)/n);
		long long t=(long long)x*n+i;
		if(t<min)
		{
			min_k=i;
			min=t;
		}
	}
	cout<<min_k+1<<endl;
}