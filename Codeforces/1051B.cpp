#include<iostream>
#define int long long
using namespace std;

int32_t main()
{
	int l, r;
	cin>>l>>r;
	cout<<"YES"<<endl;
	for(int i=l ; i<r; i+=2)
	{
		cout<<i<<" "<<i+1<<endl;
	}
}