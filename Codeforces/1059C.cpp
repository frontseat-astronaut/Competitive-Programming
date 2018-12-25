#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int k=1, i=0, half;
	while(n)
	{
		if(n==3)
		{
			cout<<k<<' '<<k<<' '<<3*k<<endl;
			return 0;
		}
		half=n-n/2;
		n/=2;
		i=0;
		while(i<half)
		{
			cout<<k<<" ";
			++i;
		}
		k<<=1;
	}

}