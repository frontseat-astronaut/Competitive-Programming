#include<iostream> 
#include<stdio.h>
using namespace std;

int coltz(unsigned int x,int limit)
{
	if(x==1)
		return 1;
	if(x>limit)
		return 0;
	if(x%2==0)
	{
		return 1+coltz(x/2,limit);
	}
	else
	{
		return 1+coltz(3*x+1,limit); 
	}	
}

int main()
{
	unsigned int A, caseno=1;
	int limit;
	while(cin>>A)
	{
		cin>>limit;
		if(limit<0) break;

		printf("Case %d: A = %d, limit = %d, number of terms = %d\n",caseno++,A,limit,coltz(A,limit));
	}
	
}