#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	if(n<2*k+1)
	{
		cout<<1<<endl;
		cout<<ceil((double)n/2)<<endl;
		return 0;
	}
	int r=n%(2*k+1);
	if(r>k)
	{
		int l=ceil((double)n/(2*k+1));
		cout<<l<<endl;
		for(int i=k+1, p=0; p<l-1; i+=2*k+1)
		{
			cout<<i<<" ";
			++p;
		}
		cout<<n-r+k+1<<endl;
		return 0;
	}
	if(r==0)
	{
		cout<<n/(2*k+1)<<endl;
		for(int i=k+1; i<=n; i+=2*k+1)
		{
			cout<<i<<" ";
		}
		cout<<endl;
		return 0;
	}
	int l=2+(n-(k+1))/(2*k+1);
	cout<<l<<endl;
	for(int i=1; i<=n-r+1; i+=2*k+1)
		cout<<i<<" ";
	cout<<endl;
}