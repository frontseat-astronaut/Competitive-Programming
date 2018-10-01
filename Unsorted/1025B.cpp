#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;

	long long g=0;
	long long A[n], B[n];
	for(int i=0; i<n; ++i)
	{
		long long a, b;
		cin>>a>>b;
		A[i]=a, B[i]=b;
		g=__gcd(g,a*b); // dunno why it's faster than storing it as an input and then iterating through it
	}

	if(g==1)
	{
		cout<<-1<<endl;
		return 0;
	}
 	
 	for(int i=0; i<n; ++i)
 	{
 		g=max(__gcd(A[i],g), __gcd(B[i],g));
 	}
 	cout<<g<<endl;

}