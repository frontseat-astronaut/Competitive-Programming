#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin>>n;

	vector<string> a;

	for(int i=0; i<n; ++i)
	{
		string s;
		cin>>s;
		a.push_back(s);
	}
	int ans=0;

	for(int i=0; i<n; ++i)
	{
		string s;
		cin>>s;

		bool flag=true;
		auto match=a.begin();
		for(auto it=a.begin(); it!=a.end(); ++it)
		{
			if((*it)==s)
			{
				flag=false;
				match=it;
//				cout<<"woho";
				break;
			}
		}
		if(flag)
		{
			++ans;
		}
		else
		{
			a.erase(match);
		}
	}
	cout<<ans<<endl;

}