#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct f
{
	int a,b;
};
struct r
{
	int a;
};

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int t[n];
		vector<f> F;
		vector<r> R;
		for(int i=0; i<n; ++i) cin>>t[i];
		sort(t,t+n);

		int time=0;
		int i;
		for( i=n-1; i>=3; i-=2)
		{
			int t1=2*t[0]+t[i-1]+t[i];
			int t2=t[0]+2*t[1]+t[i];

			if(t1<=t2)
			{
				F.push_back({t[0],t[i]});
				R.push_back({t[0]});
				F.push_back({t[0],t[i-1]});
				R.push_back({t[0]});
				time+=t1;
			}
			else
			{
				F.push_back({t[0],t[1]});
				R.push_back({t[0]});
				F.push_back({t[i-1],t[i]});
				R.push_back({t[1]});
				time+=t2;
			}
		}
		if(i==2)
		{
			F.push_back({t[0],t[2]});
			R.push_back({t[0]});
			F.push_back({t[0],t[1]});
			time+=t[0]+t[1]+t[2];
		}
		else if (i==1)
		{
			F.push_back({t[0],t[1]});
			time+=t[1];
		}
		else
		{
			R.push_back({t[0]});
			time+=t[0];
		}

		cout<<time<<endl;
		int j;
		for(j=0; j<n-2; ++j)
		{
			cout<<F[j].a<<" "<<F[j].b<<endl;
			cout<<R[j].a<<endl;
		}
		if(j<F.size())
		{
			cout<<F[j].a<<" "<<F[j].b<<endl;
		}
		if(j<R.size())
		{
			cout<<R[j].a<<endl;
		}

		if(T) cout<<endl;
	}
}