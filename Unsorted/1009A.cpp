#include<iostream>
using namespace std;

int main()
{
	int n, m;
	cin>>n>>m;

	int c[n], a[m];
	for(int i=0; i<n; ++i)
	{
		cin>>c[i];
	}
	for(int i=0; i<m; ++i)
	{
		cin>>a[i];
	}

	int i=0, j=0;
	while(i<n)
	{
		if(j>=m)
		{
			++i;
			continue;
		} 
		if(c[i]<=a[j])
		{
			++j;
		}
		++i;
	}
	cout<<j<<endl;

}