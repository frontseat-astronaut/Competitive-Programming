#include<iostream>
using namespace std;

int main()
{
	int n,d;
	cin>>n>>d;

	int x[n];
	for(int i=0; i<n; ++i)
		cin>>x[i];

	int c=2;
	for(int i=0; i<n-1; ++i)
	{
		int D=x[i+1]-x[i];
		if(2*d<D) c+=2;
		else if(2*d==D) c++;
	}
	cout<<c<<endl;
}