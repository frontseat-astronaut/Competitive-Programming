#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{
	int n, m;
	cin>>n>>m;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	sort(a, a+n);

	int maxm=a[n-1]+m;
	int i=0;
	while(m)
	{
		if(a[0]==a[n-1])
			break;
		int temp=min(m, a[n-1]-a[0]);
		m-=temp;
		a[0]+=temp;
		sort(a,a+n);
	}
	if(m)
	{
		cout<<ceil((double)m/n)+a[n-1]<<' ';
	}
	else
		cout<<a[n-1]<<' ';
	cout<<maxm<<endl;
}