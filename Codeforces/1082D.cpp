#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ff first
#define ss second

int main()
{
	int n;
	cin>>n;
	pii a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i].ff;
		a[i].ss=i+1;
	}
	sort(a, a+n);
	int cnt=0;
	for (int i = 0; i < n; ++i)
	{
		if(a[i].ff!=1)
			break;
		++cnt;
	}
	if(cnt==0)
	{
		cout<<"YES "<<n-1<<endl;
		cout<<n-1<<endl;
		for(int i=0; i<n-1; ++i)
			cout<<i+1<<" "<<i+2<<endl;
	}
	else if (cnt>0 && cnt<3)
	{
		cout<<"YES "<<n-1<<endl;
		cout<<n-1<<endl;
		swap(a[1],a[n-1]);
		for(int i=0; i<n-1; ++i)
			cout<<a[i].ss<<' '<<a[i+1].ss<<endl;
	}
	else
	{
	    if(a[n-2]>a[cnt])
		    swap(a[n-2],a[cnt]);
		for(int i=cnt; i<n-1; ++i)
		{
			a[i].ff--;
			a[i+1].ff--;
		}
		int space=0;
		for(int i=cnt; i<n; ++i)
		{
			space+=a[i].ff;
		}
		if(space<cnt)
			cout<<"NO"<<endl;
		else
		{
			cout<<"YES "<<n-cnt+1<<"\n";
			cout<<n-1<<endl;
			for(int i=cnt; i<n-1; ++i)
			{
				cout<<a[i].ss<<' '<<a[i+1].ss<<endl;
			}
			cout<<(a[n-1].ss)<<" "<<a[0].ss<<endl;
			a[n-1].ff--;
			cout<<(a[cnt].ss)<<" "<<a[1].ss<<endl;
			a[cnt].ff--;
			for(int i=2, j=cnt; i<cnt; ++i)
			{
				while(a[j].ff && i<cnt)
				{
					cout<<a[i++].ss<<" "<<a[j].ss<<endl;
					a[j].ff--;
				}
				i--;
				++j;
			}
		}
	}
}