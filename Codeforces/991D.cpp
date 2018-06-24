#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char s[2][101];
	cin>>s[0]>>s[1];

	int n=strlen(s[0]);
	int count=0;
	for(int i=0; i<n; ++i)
	{
		if(s[0][i]=='0')
		{
			if(i-1>=0)
			{
				if(s[0][i-1]=='0' && s[1][i-1]=='0')
				{
					s[0][i-1]='X';
					s[1][i-1]='X';
					s[0][i]='X';
					++count;
					continue;
				}
				else if(s[1][i]=='0' && s[1][i-1]=='0')
				{
					s[1][i]='X';
					s[1][i-1]='X';
					s[0][i]='X';
					++count;
					continue;
				}
			}
			if(i+1<n)
			{
				if(s[1][i+1]=='0' && s[1][i]=='0')
				{
					s[1][i+1]='X';
					s[1][i]='X';
					s[0][i]='X';
					++count;
					continue;
				}
				else if(s[0][i+1]=='0' && s[1][i+1]=='0')
				{
					s[0][i+1]='X';
					s[1][i+1]='X';
					s[0][i]='X';
					++count;
					continue;
				}
			}
		}
	}
	cout<<count<<endl;
//	cout<<s[0]<<endl<<s[1]<<endl;
}