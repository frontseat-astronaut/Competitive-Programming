#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	if(n&1)
	{
		cout<<0;
		exit(0);
	}

	int sum=0;
	for(int i=0; i<n; ++i)
	{
		if(s[i]=='(')
			sum++;
		else
			sum--;
	}
	int cnt=0;
	if(sum==2)
	{
		int sum=0;
		bool flag=0;
		bool minus1=0;
		for(int i=n-1; i>=0; --i)
		{
			if(s[i]==')')
				sum++;
			else
			{
				if(!minus1)
					cnt++;
				sum--;
			}
			if(sum<-2)
			{
				flag=1;
				break;
			}
			if(sum==-1)
			{
				minus1=1;
			}
		}
		if(!flag)
			cout<<cnt;
		else
			cout<<0;
	}
	else if(sum==-2)
	{
		int sum=0;
		bool flag=0;
		bool minus1=0;
		for(int i=0; i<n; ++i)
		{
			if(s[i]=='(')
				sum++;
			else
			{
				if(!minus1)
					cnt++;
				sum--;
			}
			if(sum<-2)
			{
				flag=1;
				break;
			}
			if(sum==-1)
			{
				minus1=1;
			}
		}
		if(!flag)
			cout<<cnt;
		else
			cout<<0;
	}
	else
	{
		cout<<0;
	}
}