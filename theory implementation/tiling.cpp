#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int T[n+1], f[n+1];
	for(int i=0; i<n+1; ++i)
	{
		T[i]=-1, f[i]=-1;
	}
	T[0]=1, T[1]=1;
	f[0]=0, f[1]=1;
	for(int i=2; i<=n; ++i)
	{
		T[i]=T[i-1]+T[i-2]+2*f[i-2];
		f[i]=f[i-1]+T[i-1];
	}
	cout<<T[n]<<endl;
}