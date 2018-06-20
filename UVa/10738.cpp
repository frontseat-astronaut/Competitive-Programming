#include<iostream>
#include<unordered_map>
#include<vector>
#include<stdio.h>
using namespace std;

int main()
{
	vector <int> N;
	int max=0;
	while(true)
	{
		 int n;
		 cin>>n;
		 if(!n) break;
		 N.push_back(n);
		 if(max<n)
		 	max=n;
	}

	unordered_map<int,bool>iscomp;
	unordered_map<int,int>mu, M;
	M[1]=1; 

	for(int i=2; i<=max; ++i)
	{
		if(iscomp[i]==0)
		{
			mu[i]=1;
			for(int j=2; j*i<=max; ++j)
			{
				iscomp[j*i]=1;

				if(mu[i*j]==-1)
					continue;
				if((j*i)%(i*i)==0)
				{
					mu[j*i]=-1;
					continue;
				}
				mu[j*i]++;
			}
		}

		if(mu[i]==-1)
			M[i]=M[i-1];
		else if( (mu[i])%2==0 )
			M[i]=M[i-1]+1;
		else
			M[i]=M[i-1]-1;
		
	}
	
	for(auto x: N)
	{
		int m;
		if(x==1)
			m=1;
		else if(mu[x]==-1)
			m=0;
		else if((mu[x])%2==0)
			m=1;
		else
			m=-1;
//		if(!iscomp[x]) cout<<"prime and mu[x]="<<mu[x];
		printf("%8d%8d%8d\n",x,m,M[x]);
	}	

}