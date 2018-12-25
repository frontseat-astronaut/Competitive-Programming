#include<bits/stdc++.h>
using namespace std;
int n, k, ai;
map<int, int> cnt;
vector<int>ans;

bool check(int val, vector<int>&temp)
{
	int c=0, initc;
	for(auto a: cnt)
	{
		if(a.second/val>0)
		{
			initc=c;
			c=min(c+a.second/val, k);
			for (int i = 0; i <c-initc; ++i)
			{
				temp.push_back(a.first);
			}
		}
		if(c==k)
			break;
	}
	if(c<k)
		return 0;
	else return 1;
}

int main()
{
	cin>>n>>k;
	for (int i = 0; i < n; ++i)
	{
		cin>>ai;
		cnt[ai]++;
	}
	//binary search
	int l=1, r=n, mid;
	bool isans;
	while(l<=r)
	{
		mid=(l+r)>>1;
		vector<int>temp;
		isans=check(mid, temp);
		if(isans)
		{
			ans=temp;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	for(auto ai:ans)
		cout<<ai<<" ";
}