#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		bool f=0;
		bool ans=1;
		int prev=0;
		for (int i = 0; i < n; ++i)
		{
			if(a[i]<prev)
			{
				if(f)
				{
					ans=0;
					break;
				}
				f=1;
				prev=-1;
				continue;
			}
			prev=a[i];
		}
		if(!ans)
		{
			cout<<"NO"<<endl;
			continue;
		}
		if(!f)
		{
			cout<<"YES"<<endl;
			continue;
		}
		if(a[n-1]<=a[0])
		{
			cout<<"YES"<<endl;
			continue;
		}
		cout<<"NO"<<endl;
	}
}