#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0) break;

		int d[n], k[m];
		for(int i=0; i<n; ++i)
			cin>>d[i];
		for(int i=0; i<m; ++i)
			cin>>k[i];
		sort(d,d+n);
		sort(k, k+m);

		if(n>m) 
		{
			cout<<"Loowater is doomed!"<<endl;
			continue;
		}

		bool flag=true;
		long long cost=0;
		for(int i=0, j=0; i<n; ++i)
		{
			while(j<m && k[j]<d[i])
				++j;
			if(j==m)
			{
				flag=false;
				break;
			}
			cost+=k[j];
			j++;
		}
		if(flag)
			cout<<cost<<endl;
		else
			cout<<"Loowater is doomed!"<<endl;
	}
}