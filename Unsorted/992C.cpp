#include<iostream>
#define int long long
using namespace std;

int32_t main()
{
	int n,k;
	cin>>n>>k;
	bool flag=1;
	for(int i=1; i<=k; ++i)
	{
		if((n+1)%i!=0)
		{
			flag=0;
			break;
		}
	}
	if(flag)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}