#include<iostream>
#define int long long
using namespace std;

int32_t main()
{
	int T,N, sum=0, index, days;
	int A[100001];
	cin>>T;
	while(T--)
	{
		cin>>N;
		sum=0;
		for (int i = 0; i < N; ++i)
		{
			cin>>A[i];
			sum+=A[i];
			A[i]=sum;
		}
		index=0, days=0;
		while(index<N-1)
		{
			index+=A[index];
			days++;
		}
		cout<<days<<endl;
	}
}