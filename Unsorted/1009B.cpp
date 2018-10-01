#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
	char s[100001];
	cin>>s;

	int l=strlen(s);
	int ones=0, start=0, k=0;
	for(int i=0; i<l; ++i)
	{
		if (s[i]=='2')
		{
			while(i<l && s[i]!='0') ++i;
			i--;
			sort(s+start, s+i+1);
			start=i+1;
		}
	}
	sort(s+start, s+l);
	cout<<s<<endl;
}