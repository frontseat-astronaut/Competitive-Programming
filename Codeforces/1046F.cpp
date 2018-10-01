#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int a[N];
	for(int i=0; i<N; ++i)
	{
		cin>>a[i];
	}
	int x,f;
	cin>>x>>f;
	long long ans=0;
	for (int i = 0; i < N; ++i)
	{
		ans+=a[i]/(x+f);
		a[i]=a[i]%(x+f);
		if(a[i]>x)
		{
			ans++;
		}
	}
	cout<<ans*f<<endl;
}