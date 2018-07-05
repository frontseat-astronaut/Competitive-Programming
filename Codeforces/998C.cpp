#include<iostream>
using namespace std;

int main()
{
	int n,x,y;
	cin>>n>>x>>y;

	bool a[n];
	getchar();
	for(int i=0; i<n; ++i)
	{
		char ch=getchar();
		a[i]=ch-'0';
	}
	int zeroes[n];
	int N=0, num=0;
	for(int i=0; i<n; ++i)
	{
		if(a[i]==0)
		{
			while(!a[i] && i<n)
			{
				num++;
				++i;
			}
			--i;
			zeroes[N++]=num;
			num=0;
		}
	}
	if(N==0) cout<<0<<endl;
	else cout<<min((long long)N*y, (long long)(N-1)*x+y)<<endl;
	
}