#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Ends
{
	int id;
	long long x;
};

bool cmp(Ends a, Ends b)
{
	return a.x<b.x;
}

int main()
{
	int n;
	cin>>n;
	long long cnt[n+1]={0};
	vector<Ends>E;
	for(int i=0; i<n; ++i)
	{
		long long l;
		cin>>l;

		long long r;
		cin>>r;

		E.push_back({i+1,l});
		E.push_back({-(i+1),r});
	}
	sort(E.begin(), E.end(), cmp);

	int count=0;
	long long coord=E[0].x;
	for(int i=0; i<2*n; ++i)
	{
		long long x=E[i].x;
		int r=0, l=0; 

		while(i<2*n && E[i].x==x)
		{
			if(E[i].id>0) ++l;
			else ++r;
			++i;
		}
		i--;

		cnt[count]+=x-coord-1;
		cnt[count+l]++;
		count+=l;
		count-=r;
		coord=x;
	}
	for(int i=1; i<=n; ++i)
		cout<<cnt[i]<<" ";
	cout<<endl;
}