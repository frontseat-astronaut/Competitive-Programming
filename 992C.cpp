#include<iostream>
using namespace std;

long long p= 1000000007;	

long long power(long long x, long long  y)
{
    long long temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);       
    if (y%2 == 0)
        return (temp*temp)%p;
    else
    {
    	return (x*temp*temp)%p;
    }
}

int main()
{
	long long x,k;
	cin>>x>>k;
//	cout<<k<<endl;

	if(x==0) 
	{
		cout<<0<<endl;
		return 0;
	}
//	cout<<power(2,k)<<endl;	
	long long ans= ( power(2,k) * ( ( 2 * (x%p) - 1) )%p )%p;
//	cout<<ans<<endl;
	ans=(ans+1)%p;
	if(ans<0)
	{
		ans=1000000007+ans;
	}
	cout<<ans<<endl;
}