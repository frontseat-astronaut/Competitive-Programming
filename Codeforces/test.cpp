#include<iostream>
#define int long long
using namespace std;

int32_t main()
{
	int n=80, m=40;
	int k=0;
	cout<<n<<" "<<m<<"\n";
	for(int i=0; i<n; ++i)
	{
		if(i&1)
		{
			cout<<2<<" "<<k<<endl;
			k=(k+1)%m;
		}
		else
			cout<<1<<endl;
	}
}