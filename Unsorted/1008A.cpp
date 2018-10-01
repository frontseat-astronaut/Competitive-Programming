#include<iostream>
using namespace std;

int main()
{
	string s;
	cin>>s;

	int l=s.length();
	bool flag=true;
	for(int i=0; i<l; ++i)
	{
		switch(s[i])
		{
			case 'a': case 'e': case 'i': case 'o': case 'u':
			case 'n': break;

			default: 

				if(i==l-1)
				{
					flag=false;
					break;
				}
				if(!(s[i+1]=='a' || s[i+1]=='e' ||s[i+1]=='i' ||s[i+1]=='o' ||s[i+1]=='u' ))
				{
					flag=false;
					break;
				}
				break;	
		}
		if(!flag) break;
	}
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}