#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin>>T;

	while(T--)
	{
		int W;
		cin>>W;

		bool ans=true;
		int diff;

		for(int i=0; i<W; ++i)
		{
			int n,s;
			cin>>n>>s;

			if(i==0)
			{
				diff=n-s;
				continue;
			}

			if(n-s!=diff)
			{
				ans=false;
			}
		}
		if(ans)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;

	}
}