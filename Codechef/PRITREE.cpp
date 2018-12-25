#include<bits/stdc++.h>
using namespace std;
int N=40000;
int main()
{
	vector <bool> isprime(40005,1);
	isprime[0]=0, isprime[1]=0;
	for(int i=2; i*i<=N; ++i)
	{
		if(isprime[i])
		{
			for(int j=i; j*i<=N; ++j)
			{
				isprime[j*i]=0;
			}
		}
	}

	int n;
	cin>>n;
	int v[n];
	vector<int> primes, cons, pcons;
	map<int,vector<int>>psum, csum;
	for(int i=0; i<n; ++i)
	{
		if(isprime[v[i]])
			primes.pb(i+1);
		
	}
	for(auto p:primes)
	{
		for(int i=0; i<n; ++i)
		{
			if(!isprime[i] && )
			{

			}
		}
	}

}