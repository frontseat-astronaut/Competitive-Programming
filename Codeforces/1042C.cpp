#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	int n;
	cin>>n;
	int a[n];
	int ncnt=0;
	vector<int>pick;
	bool p[n]={};
	int pcnt=0;
	int maxni, maxn=-10000000000;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		if(a[i]<0)
		{
			ncnt++;
			if(a[i]>maxn)
			{
				maxn=a[i];
				maxni=i;
			}
		}
		if(a[i]==0)
		{
			p[i]=1;
			pick.push_back(i);
			++pcnt;
		}
	}
	if(ncnt%2)
	{
		pick.push_back(maxni);
		pick[maxni]=1;
		++pcnt;
	}
	
	int moves=0;
	for(int i=1; i<pcnt; ++i)
	{
		cout<<1<<" "<<pick[i]+1<<" "<<pick[0]+1<<endl;
		++moves;
	}
	if(moves==n-1)
		return 0;
	cout<<2<<' '<<pick[0]+1<<endl;
	++moves;
	if(moves==n-1)
		return 0;
	int j=0;
	while(p[j]&&j<n)
		++j;
	for(int i=j+1; i<n; ++i)
	{
		if(!p[i])
		{
			cout<<1<<" "<<i+1<<" "<<j+1<<endl;
			++moves;
		}

		if(moves==n-1)
			return 0;
	}

	
}