#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		map<int,vector<int>>m;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			m[a[i]].push_back(i+1);
		}
		bool flag=0;
		for(auto ai:m)
		{
			if(ai.second.size()<2)
				continue;
			int cnt=0;
			for(auto id:ai.second)
			{
				if(m.find(id)!=m.end())
					cnt++;
				if(cnt>1)
				{
					flag=1;
					break;
				}
			}
			if(flag)
				break;
		}
		if(flag)
			cout<<"Truly Happy"<<endl;
		else
			cout<<"Poor Chef"<<endl;
	}
}