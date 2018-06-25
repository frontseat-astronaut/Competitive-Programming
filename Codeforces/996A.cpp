#include<iostream>
using namespace std;
int main()
{
	int n;
	int arr[5]={1,5,10,20,100};

	cin>>n;

	int i=4, count=0;
	for(; i>=0 ; --i)
	{
		count+=n/arr[i];
		n=n%arr[i];
	}
	cout<<count<<endl;
}