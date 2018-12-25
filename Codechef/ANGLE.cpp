#include<bits/stdc++.h>
#define int long long
using namespace std;

#define pii pair<int,int>
#define f first
#define s second

bool cmp(pii a, pii b)
{
	return a.f<b.f;
}

int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, p, q, cos;

		cin>>n>>p>>q;
		pii a[n];
		int  a_[n];
		for(int i=0; i<n; ++i)
		{
			cin>>a[i].f;
			a[i].s=i+1;
			a_[i]=a[i].f*a[i].f*q;
		}

		sort(a,a+n, cmp);
		sort(a_,a_+n);
		int ax, ay, az;
		double minm=1.1, cosine;
		bool flag=0;
		for(int b=n-1; b>=0; --b)
		{
			for(int c=b-1; c>=0; --c)
			{
				cos=a_[b]+a_[c]-2*a[b].f*a[c].f*p+1;
				auto it=lower_bound(a_, a_+n,cos);
				int k=it-a_;
				k--;
				while((k==b || k==c)&& k>=0)
					--k;

				cosine=(double)(a_[b]/q+a_[c]/q-a_[k]/q)/(2*a[b].f*a[c].f);
				if(k>=0 && cosine<1)
				{
					flag=1;
					if(minm>cosine)
					{
						ax=a[k].s; ay=a[b].s; az=a[c].s;
						minm=cosine;
					} 
				}
			}
		}
		if(flag==0)
		{
			cout<<-1<<endl;
		}
		else
			cout<<ax<<' '<<ay<<' '<<az<<endl;
	}
}