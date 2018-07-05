#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int a[n], map[101]={0};
	int max=0;
	for(int i=0; i<n; ++i)
	{
		cin>>a[i];
		map[a[i]]++;
		if(max<map[a[i]])
			max=map[a[i]];
	}
	cout<<max<<endl;

}