#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<math.h>
using namespace std;

struct mrkr
{
	int id;
	long double x;
};

bool cmp(mrkr a, mrkr b)
{
	return a.x<b.x;
}

int main()
{
	int n;
	long double l,w;
	int caseno=1;
	while(cin>>n>>l>>w)
	{
		vector<mrkr>S;
		long double R[n+1];
		for(int i=0; i<n; ++i)
		{
			long long c,r;
			cin>>c>>r;
			if(2*r<=w) 
			{
				n--;
				--i;
				continue;
			}
			S.push_back({-(i+1),c+sqrt(( long double)r*r-( long double)w*w/4)});
			S.push_back({(i+1),c-sqrt(( long double)r*r-( long double)w*w/4)});
			R[i+1]=c+sqrt(( long double)r*r-( long double)w*w/4);
		}
		sort(S.begin(), S.end(), cmp);
//		for(auto s: S)
//			cout<<s.id<<": "<<s.x<<" ";
//		cout<<endl;
		long double x=0;
		int k=0;
		set<int>layers;
		bool pos=true;
		int ans=0;
		while(x<l )
		{
//			cout<<x<<": ";
			while(k<2*n && (S[k].x<x || fabs(S[k].x-x)<0.00000001))
			{
				if(S[k].id>0)
					layers.insert(S[k].id);
				else
					layers.erase(-S[k].id);
				++k;
			}
			if(layers.size()==0)
			{
				pos=false;
				break;
			}

			long double maxm=x;
			int maxi;
			for(auto i:layers)
			{
//				cout<<i<<" ";
				if(R[i]>maxm || fabs(R[i]-maxm)<0.00000001)
				{
					maxm=R[i];
					maxi=i;
				}
			}
			ans++;
			x=R[maxi];
//			cout<<endl;
		}
		caseno++;
//		if(caseno!=592) continue;
		if(pos) cout<<ans<<endl;
		else cout<<-1<<endl;
	}
}