#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int L=s.length();
	for(int i=1 ;i<L; ++i)
	{
		if(s[i]==s[i-1])
		{
			if(s[0]==s[L-1])
				break;
			for(int j=0, k=i-1; j<k; ++j, --k)
			{
				swap(s[j],s[k]);
			}
			for(int j=i, k=L-1; j<=k; ++j, --k)
			{
				swap(s[j],s[k]);
			}
		}
	}
	int maxm=0, cnt=1;
	for(int i=1; i<L; ++i)
	{
		if(s[i]==s[i-1])
		{
			maxm=max(maxm, cnt);
			cnt=0;
		}
		cnt++;
	}
	cout<<maxm<<endl;
}