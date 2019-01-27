#include<bits/stdc++.h>
#define int long long
#define ff first
#define ss second
#define pii pair<int,int>
using namespace std;

int32_t main()
{
	int n;
	cin>>n;
	string s;
	map<int,int>m;
	int per=0;
	int ans=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>s;
		vector<char>S;
		for(auto ch: s)
		{
			if(ch=='(')
				S.push_back('(');
			else
			{
				if(!S.empty() && S.back()=='(')
					S.pop_back();
				else
					S.push_back(')');
			}
		}
		if(S.empty())
		{
			per++;
			continue;
		}
		if(S.back()=='(')
		{
			if(S.front()!=')')
			{
				if(m[-S.size()]>0)
				{
					ans++;					
					m[-S.size()]--;
				}
				else
				{
					m[S.size()]++;
				}
			}
		}
		else 
		{
			if(m[S.size()]>0)
			{
				ans++;					
				m[S.size()]--;
			}
			else
			{
				m[-S.size()]++;
			}
		}
	}
	ans+=per>>1;
	cout<<ans;
}