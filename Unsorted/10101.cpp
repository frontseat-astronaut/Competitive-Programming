#include<iostream>
#define int long long
using namespace std;

string dac(int N)
{
	if(N==0) return "";
	if(N>=10000000)
	{
		string ans=dac(N/10000000)+" kuti";
		string temp=dac( N-(N/10000000)*10000000);
		if(temp!="")
		{
			ans=ans+" "+temp;
		}
		return ans;
	}
	if(N>=100000)
	{
		string ans=to_string(N/100000)+" lakh";
		string temp=dac(N-(N/100000)*100000);
		if(temp!="")
		{
			ans=ans+" "+temp;
		}
		return ans;
	}
	if(N>=1000)
	{
		string ans=to_string(N/1000)+" hajar";
		string temp=dac(N-(N/1000)*1000);
		if(temp!="")
		{
			ans=ans+" "+temp;
		}
		return ans;
	}
	if(N>=100)
	{
		string ans=to_string( N/100 )+" shata";
		string temp=dac(N-(N/100)*100);
		if(temp!="")
		{
			ans=ans+" "+temp;
		}
		return ans;
	}
	return to_string(N);
}

int32_t main()
{
	int N, caseno=1;
	while(cin>>N)
	{
		printf("%4d",caseno++);
		string ans=dac(N);
		if(ans=="")
			cout<<". "<<0<<endl;
		else
			cout<<". "<<ans<<endl;
	}
}