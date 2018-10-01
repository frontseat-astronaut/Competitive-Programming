#include<iostream>
#include<math.h>
#define int long long
using namespace std;

int32_t main()
{
	int n,k;
	cin>>n>>k;
	if(k%n==0)
	{
		cout<<k/n<<endl;
		return 0;
	}
	cout<<k/n+1<<endl;
}