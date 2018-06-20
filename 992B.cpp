#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{
	int l,r,x,y;
	cin>>l>>r>>x>>y;

	long long N=(long long)x*y;
	int count=0;
	long long i=ceil( (double)l/x );
	while( i*x<=r && i*x<=sqrt(N) )
	{
//		cout<<"yo"<<endl;
//		cout<<i*x<<endl;
		if(N%(i*x)==0)
		{
			if(N/(i*x)>r)
			{
				i++;
				continue;
			} 
			if(__gcd(i*x, N/(i*x))==x)
			{
				if(i*x==N/(i*x)) ++count;
				else count+=2;
			}
		}
		++i;
	}

	cout<<count<<endl;
}