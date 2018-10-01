#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, a, b;
	cin>>n>>a>>b;
	int A[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>A[i];
	}
	int cost=0;
	bool flag=1;
	for(int i=0, j=n-1; i<=j; ++i, --j)
	{
		if(A[i]==2 && A[j]==2)
		{
			if(j==i)
				cost+=min(a,b);
			else cost+=2*min(a,b);
		}
		else if ((A[i]==2 && A[j]==1) || (A[i]==1 && A[j]==2))
		{
			cost+=b;
		}
		else if ((A[i]==2 && A[j]==0) || (A[i]==0 && A[j]==2))
		{
			cost+=a;
		}
		else if(A[i]!=A[j])
		{
			flag=0;
			break;
		}
	}
	if(!flag)
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<cost<<endl;
}