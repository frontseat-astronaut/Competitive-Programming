#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int T, N;
	int A[100001], B[100001];
	cin>>T;
	while(T--)
	{
		cin>>N;
		for (int i = 0; i < N; ++i)
		{
			cin>>A[i];
		}
		for (int i = 0; i < N; ++i)
		{
			cin>>B[i];
			B[i]-=A[i];
		}
		bool flag=1;
		for(int i=N-1; i>=2; --i)
		{
			if(B[i]<0)
			{
				flag=0;
				break;
			}
			if(B[i]%3==0)
			{
				B[i-1]-=2*(B[i]/3);
				B[i-2]-=(B[i]/3);
			}
			else
			{
				flag=0;
				break;
			}
		}
		if(B[0] || B[1])
			flag=0;
		if(flag)
		{
			cout<<"TAK\n";
		}
		else
			cout<<"NIE\n";
	}
}