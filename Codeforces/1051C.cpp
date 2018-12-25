#include<iostream>
#include<map>
#include<set>
using namespace std;

int main()
{
	int n, ones=0, mt2=0;
	map<int,int> m;
	cin>>n;
	int a[n];
	char ans[n+1]={};
	for(int i=0; i<n; ++i)
	{
		cin>>a[i];
		m[a[i]]++;
		if(m[a[i]]==1)
		{
			ones++;
		}
		else if(m[a[i]]==2)
			ones--;
		else if(m[a[i]]==3)
			mt2=a[i];
	}
	if(ones%2)
	{
		if(mt2==0)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	int A=0, B=0;
	for(int i=0, j=0; i<n; ++i)
	{
		if(m[a[i]]==1)
		{
			if(j%2)
			{
				ans[i]='B';
				B++;
			}
			else
			{
				ans[i]='A';
				A++;
			}
			++j;
		}
	}
	if(ones%2)
	{
		for(int i=0; i<n; ++i)
		{
			if(a[i]==mt2)
			{
				if(A>B)
				{
					ans[i]='B';
				}
				else
					ans[i]='A';
				mt2=0;
			}
			else if(!ans[i])
			{
				if(A>B)
					ans[i]='A';
				else
					ans[i]='B';
			}
		}
	}
	else
	{
		for(int i=0; i<n; ++i)
		{
			if(!ans[i])
			{
				ans[i]='B';
			}
		}
	}
	
	ans[n]='\0';
	cout<<ans<<endl;

}