#include<iostream>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n;
	int a[n];
	int suma=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		suma+=a[i];
	}
	cin>>m;
	int b[m];
	int sumb=0;
	for (int i = 0; i < m; ++i)
	{
		cin>>b[i];
		sumb+=b[i];
	}
	if(suma!=sumb)
	{
		cout<<-1<<endl;
		return 0;
	}
	int i=0, j=0;
	int A=0, B=0;
	int k=0;
	while(i<n && j<m)
	{
		if(A+a[i]==B+b[j])
		{
			A=0;
			B=0;
			++k;
			++i;
			++j;
		}
		else if(A+a[i]<B+b[j])
		{
			A+=a[i];
			i++;
		}
		else
		{
			B+=b[j];
			j++;
		}
	}
	cout<<k<<endl;
}