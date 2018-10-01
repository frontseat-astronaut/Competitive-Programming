#include<iostream>
using namespace std;

int main()
{
	int n, k;
	cin>>n>>k;
	string s;
	cin>>s;
	int cnt[256]={};
	for(int i=0; i<n; ++i)
	{
		cnt[s[i]]++;
	}
	int min=n;
	for(int i=65; i<65+k; ++i)
	{
		if(min>cnt[i])
			min=cnt[i];
	}
	cout<<k*min<<endl;

}