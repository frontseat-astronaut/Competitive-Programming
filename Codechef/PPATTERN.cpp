#include<iostream>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
	int N;
	cin>>N;
	int a[N][N]={};
	int cnt=1;
	for(int k=0; k<=2*(N-1); ++k)
	{
		for(int i=max(0, k-N+1); i<=min(k, N-1); ++i)
		{
			a[i][k-i]=cnt++;
		}
	}
	for(int i=0; i<N; ++i)
	{
		for(int j=0; j<N; ++j)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}
}