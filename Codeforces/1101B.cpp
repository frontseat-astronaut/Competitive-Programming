#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	string s;
	cin>>s;
	int n=s.length();
	int maxm=0;
	string acc="[:|:]";
	int presum[n]={}, sum=0;
	for(int i=0; i<n; ++i)
	{
		if(s[i]=='|')
		{
			sum++;
		}
		presum[i]=sum;
	}
	int i, j, k;
	for(i=0, k=0; i<s.length() && k<=1; ++i)
	{
		if(s[i]==acc[k])
		{
			k++;
		}
	}
	i--;
	for(j=s.length()-1, k=0; j>=0 && k<=1; --j)
	{
		if(s[j]==acc[4-k])
		{
			k++;
		}
	}
	j++;
	if(i>=j)
	{
		cout<<-1;
		exit(0);
	}
	cout<<(presum[j]-presum[i]+4);
}