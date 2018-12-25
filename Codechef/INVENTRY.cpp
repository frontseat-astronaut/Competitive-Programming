#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, n=0;
		cin>>N;
		string r;
		cin>>r;

		vector<int>a;
		int i=0,j;
		while(i<N)
		{
			j=i;
			while(r[i]==r[j] && j<N)
				++j;
			j--;
			if(r[i]=='.')
				a.push_back( -(j+1-i) );
			else
				a.push_back(j+1-i);
			n++;
			i=j+1;
		}
		if(n==1)
		{
			cout<<0<<endl;
			continue;
		}
		int ans=0, l, spaces=0, right=0;
		bool flag=1;

		for(int i=0; i<n; ++i)
		{
			if(a[i]>0 && i==0)
				continue;
			if(a[i]>0)
			{
				if(i+1==n)
				{
					flag=0;
					break;
				}
				if(-a[i+1]<a[i] && i!=n-2)
				{
					right+=a[i]+a[i+1];
				}
			}
		}
		if(!flag)
		{
			cout<<-1<<endl;
			continue;
		}
		if(-a[n-1]<right)
			flag=0;

		int temp[n];
		for(int i=0; i<n; ++i)
		{
			temp[i]=a[i];
		}
		for(int i=n-1; i>=0 && right; --i)
		{
			if(a[i]<0)
			{
				continue;
			}
			if(a[i]>0 && i==0)
				break;

			if(-temp[i+1]<temp[i])
			{
				right-=temp[i]+temp[i+1];
			}
			if(!right)
				break;
			ans+=a[i]*right;
			a[i+1]+=right;
			a[i-1]-=right;		
		}

		for(int i=0; i<n; ++i)
		{
			if(a[i]>0 && i==0)
				continue;
			if(a[i]<0)
			{
				spaces+=-a[i];
				continue;
			}
			ans+=(a[i]-1)*a[i]/2;
			ans+=a[i]*spaces+a[i]*(a[i]-1)/2;
			
		}
		if(!flag)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
	}
}