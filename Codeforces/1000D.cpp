#include<iostream>
#define p 998244353
using namespace std;

int sub=0;
int a[1001];
int n;
int C[1001][1001];
int F[1001];

int main()
{
	for(int i=1; i<1001; ++i)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1; j<i; ++j)
		{
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
		}
	}
	cin>>n;

	for(int i=0; i<n; ++i)
	{
		cin>>a[i];
	}

	F[n-1]=0;

	for(int k=n-2; k>=0; --k)
	{
		if(a[k]<=0) 
		{
			F[k]=0;
			continue;
		}
		if(a[k]>n-1-k)
		{
			F[k]=0;
			continue;	
		}
		F[k]=C[n-1-k][a[k]];
		int i=k+a[k]+1;
		while(i<n)
		{
			F[k]=( F[k] + ((long long)C[i-k-1][a[k]]*F[i])%p )%p;
			++i;
		}
		sub=(sub+F[k])%p;
	}

	cout<<sub<<endl;
//	for(int i=0; i<n; ++i)
//		cout<<F[i]<<" ";
}