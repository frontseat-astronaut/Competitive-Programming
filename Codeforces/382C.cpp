#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#define int long long
using namespace std;

int32_t main()
{
	int n;
	cin>>n;
	int a[n];
	set <int> ans;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	sort(a,a+n);
	if(n==1)
	{
		cout<<-1<<endl;
		return 0;
	}
	if(n==2)
	{
		ans.insert(a[0]-(a[1]-a[0]));
		if((a[1]-a[0])%2==0)
			ans.insert((a[1]+a[0])/2);
		ans.insert(a[1]+a[1]-a[0]);
		cout<<ans.size()<<endl; 
		for(auto num: ans)
				cout<<num<<" ";
			cout<<endl;
		return 0;
	}
	if(n==3)
	{
		int d1=a[1]-a[0], d2=a[2]-a[1];
		if(d1==d2)
		{
			ans.insert(a[0]-(a[1]-a[0]));
			ans.insert(a[2]+a[1]-a[0]);
			cout<<ans.size()<<endl;
			for(auto num: ans)
				cout<<num<<" ";
			cout<<endl;
			return 0;
		}
		else if(d1==2*d2)
		{
			ans.insert(a[0]+d2);
			cout<<ans.size()<<endl;
			for(auto num: ans)
				cout<<num<<" ";
			cout<<endl;
			return 0;
		}
		else if(2*d1==d2)
		{
			ans.insert(a[1]+d1);
			cout<<ans.size()<<endl;
			for(auto num: ans)
				cout<<num<<" ";
			cout<<endl;
			return 0;
		}
		else
		{
			cout<<0<<endl;
			return 0;
		}
	}
	map<int, int>diff;
	int morethan1=-1;
	bool flag=0;
	for (int i = 1; i < n; ++i)
	{
		diff[a[i]-a[i-1]]++;
		if(diff[a[i]-a[i-1]]>1)
		{
			if(morethan1!=a[i]-a[i-1] && morethan1!=-1)
			{
				flag=1;
				break;
			}
			morethan1=a[i]-a[i-1];
		}
	}
	for(auto d:diff)
	{
		if(d.first==morethan1)
			continue;
		if(d.first!=morethan1*2)
		{
			flag=1;
			break;
		}
	}
//	cout<<diff.size()<<endl;
	if(flag || diff.size()>2)
	{
		cout<<0<<endl;
		return 0;
	}
	if(diff.size()==1)
	{
		ans.insert(a[0]-morethan1);
		ans.insert(a[n-1]+morethan1);
			
		cout<<ans.size()<<endl;
		for(auto num: ans)
			cout<<num<<" ";
		cout<<endl;
		return 0;
	}
	for(int i=1; i<n; ++i)
	{
		if(a[i]-a[i-1]!=morethan1)
		{
			ans.insert((a[i]+a[i-1])/2);
			break;
		}
	}
	cout<<ans.size()<<endl;
	for(auto num: ans)
		cout<<num<<" ";
	cout<<endl;

}