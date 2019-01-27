#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
	int n;
	cin>>n;
	int x[n], y[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>x[i]>>y[i];
	}
	sort(x, x+n);
	sort(y, y+n);
	int a[n], b[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i]>>b[i];
	}
	sort(a, a+n);
	sort(b, b+n);
	int Tx, Ty;
	if(a[0]+x[0]==a[n-1]+x[n-1]) Tx=a[0]+x[0];
	else Tx=a[n-1]+x[0];
	if(b[0]+y[0]==b[n-1]+y[n-1]) Ty=b[0]+y[0];
	else Ty=b[n-1]+y[0];
	cout<<Tx<<' '<<Ty;
}