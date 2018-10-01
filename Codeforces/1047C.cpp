#include<bits/stdc++.h>
using namespace std;
int m[15000005];
bool np[150000005];
int gcd(int a, int b)
{

    if(b == 0) {
            return a;
    }
    else {
        return gcd(b, a % b);
    }
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int a[n];
	int g=0;

	for(int i=0; i<n; ++i)
	{
		cin>>a[i];
		g=gcd(a[i],g);
	}
	for (int i = 0; i < n; ++i)
	{
		a[i]/=g;
		m[a[i]]++;
	}
	int maxm=0;
	for(int i=2; i<=15000000; ++i)
	{
		if(!np[i])
		{
			int cnt=0;
			for(int j=1; j*i<=15000000; ++j)
			{
				np[i*j]=1;
				if(m[i*j])
					cnt+=m[i*j];
			}
			maxm=max(cnt, maxm);
		}
	}
	if(maxm==0)
		cout<<-1<<endl;
	else
		cout<<n-maxm<<endl;	
}