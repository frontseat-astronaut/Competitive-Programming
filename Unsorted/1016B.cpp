#include<iostream>
using namespace std;

int main()
{
	int n, m, q;
	cin>>n>>m>>q;

	char s[n+1];
	cin>>s;
	char t[m+1];
	cin>>t;

	int arr[n+1]={};
	for(int i=0; i<n; ++i)
	{
		bool flag=true;
		for(int j=i; j<n && j-i<m; ++j)
			if(t[j-i]!=s[j])
			{
				flag=false;
				break;
			}
		if(flag) arr[i]=1;
//		cout<<arr[i]<<" ";
	}
	cout<<endl;
	for(int i=1; i<n; ++i)
	{
		arr[i]=arr[i-1]+arr[i];
//		cout<<arr[i]<<" ";
	}
	while(q--)
	{
		int l, r;
		cin>>l>>r;
		l--;
		r--;
		if(r-l+1<m)
		{
			cout<<0<<endl;
			continue;
		}
		if(l==0)
		{
			cout<<arr[r-m+1]<<endl;
			continue;
		}
		cout<<arr[r-m+1]-arr[l-1]<<endl;
	}
}