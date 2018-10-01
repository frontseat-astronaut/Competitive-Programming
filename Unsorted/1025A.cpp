#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	char s[n+1];
	cin>>s;
	int chmap[26]={};
	for(int i=0; i<n; ++i)
	{
		chmap[s[i]-'a']++;
	}
	if(n>26) 
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	bool flag=0;
	for(int i=0; i<26; ++i)
	{
		if(chmap[i]>1)
		{
			flag=1;
			break;
		}
	}
	if(n==1) cout<<"Yes"<<endl;
	else if(flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}