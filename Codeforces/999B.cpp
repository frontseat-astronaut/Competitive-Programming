#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	char str[n];
	cin>>str;

	for(int i=1; i<=n; ++i )
	{
		if(n%i!=0) continue;
		for(int j=0, k=i-1; j<=k; ++j, --k)
		{
			swap(str[j],str[k]);
		}
	}
	cout<<str<<endl;
}