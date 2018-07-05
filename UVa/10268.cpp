#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

long long h(int n, int k, vector<int>a, int x)
{
	if(k==0) return (long long)a[0]*n;
	return (long long)(n-k)*a[k]+(long long)x*h(n,k-1,a,x);
}

int main()
{
	int x;
	while(cin>>x)
	{
		int num,n=0;
		char ch;
		vector<int>a;
		while(cin>>num)
		{
			a.push_back(num);
			++n;

			ch=getchar();
			if(ch=='\n') break;
		}
		n--;
		if(n==0)
		{
			cout<<0<<endl;
			continue;
		} 
		long long sum=0, xi=1;
		for(int i=n-1; i>=0; --i)
		{
			sum+=a[i]*xi*(n-i);
			xi*=x;
		}
		cout<<sum<<endl;
	}
}