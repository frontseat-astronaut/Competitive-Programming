#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N, n=0, ans=0, gcnt=0;
	cin>>N;
	string s;
	cin>>s;
	vector<int>a;
	int i=0, cnt;
	char ch;

	while(i<N)
	{
		ch=s[i];
		cnt=0;
		while(i<N && ch==s[i])
		{
			++i;
			++cnt;
		}
		a.push_back( ((ch=='G')?1:-1)*cnt );
		ans=max(ans, a[n]);
		gcnt+=(ch=='G');
		n++;
	}

	if(n==1)
	{
		ans=(ch=='G')?N:0;
		cout<<ans<<endl;
		return 0;
	}
	if(n==2)
	{
		if(a[0]>0)
			cout<<a[0]<<endl;
		else
			cout<<a[1]<<endl;
		return 0;
	}
	for(int i=0; i<n; ++i)
	{
		if(a[i]==-1)
		{
			if(i>0 && i<n-1)
			{
				if(i<n-3|| i>2)
				{
					ans=max(ans, a[i-1]+a[i+1]+1);
				}
				else
					ans=max(ans, a[i-1]+a[i+1]);
			}
			else if(i==0)
			{
				if(i<n-3)
					ans=max(ans, a[i+1]+1);
			}
			else if (i==n-1)
			{
				if(i>2)
					ans=max(ans, a[i-1]+1);
			}
		}
	}
	for(int i=0; i<n; ++i)
	{
		if(a[i]<0)
		{
			if(i>0 && gcnt>1)
			{
				ans=max(ans, a[i-1]+1);
			}
			if(i<n-1 && gcnt>1)
				ans=max(ans, a[i+1]+1);
		}
	}
	cout<<ans<<endl;
}