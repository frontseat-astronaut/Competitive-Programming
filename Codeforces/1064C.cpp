#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int cc[256]={};
	for (int i = 0; i < n; ++i)
	{
		cc[s[i]]++;
	}
	for(char ch='a'; ch<='z'; ++ch)
		while(cc[ch]--)
			cout<<ch;
}