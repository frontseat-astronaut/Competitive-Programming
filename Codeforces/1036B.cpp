#include<iostream>
#define int long long
using namespace std;

int32_t main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		if(n>k || m>k)
		{
			cout<<-1<<endl;
			continue;
		}
		bool p1=(k+n)%2, p2=(k+m)%2;
		if(!p1 && !p2)
		{
			cout<<k<<endl;
		}
		else if((p1 && !p2)||(!p1 && p2))
		{
			cout<<max((int)0,k-1)<<endl;
		}
		else
		{
			cout<<max((int)0,k-2)<<endl;
		}

	}
}