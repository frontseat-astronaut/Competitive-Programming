#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		a[i]--;
	}

	vector<vector<int>> prefix_wins(2,vector<int>(n+1, 0));
	vector <vector<int>> where(2, vector<int>(2*n+1, INT_MAX));
	int sums[2]={};
	for(int i=0; i<n; ++i)
	{
		sums[a[i]]++;
		prefix_wins[0][i]=sums[0];
		prefix_wins[1][i]=sums[1];
		where[a[i]][sums[a[i]]]=i;
	}

	vector<pair<int,int>>st;
	for(int t=1; t<=n; ++t)
	{
		int idx=0;
		int pnts[2]={};
		int set[2]={};
		int next[2];
		bool isok=1;
		bool winner, gw;

		while(idx<n)
		{
			next[0]=where[0][pnts[0]+t];
			next[1]=where[1][pnts[1]+t];

			if(next[0]>=n && next[1]>=n)
			{
				isok=0;
				break;
			}
			winner=(next[0]<next[1])?0:1;
			idx=next[winner];
			set[winner]++;
			pnts[0]=prefix_wins[0][idx];
			pnts[1]=prefix_wins[1][idx];
			idx++;
		}
		gw=(set[0]>set[1])?0:1;
		if(isok && set[0]!=set[1] && a[n-1]==gw )
		{
			st.push_back({max(set[0],set[1]),t});
		}
	}
	sort(st.begin(), st.end());
	cout<<st.size()<<"\n";
	for(auto p:st)
		cout<<p.first<<" "<<p.second<<"\n";
}