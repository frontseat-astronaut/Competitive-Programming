#include<iostream>
using namespace std;

int main()
{
	string a,b;
	cin>>a;
	cin>>b;

	if(a.length()>b.length())
		swap(a,b);

	int la=a.length(), lb=b.length();
	int k;
	for(k=0; k<la; ++k)
	{
		if(a[la-k-1]!=b[lb-k-1]) break;
	}
	cout<<(la-k)+(lb-k)<<endl;
}