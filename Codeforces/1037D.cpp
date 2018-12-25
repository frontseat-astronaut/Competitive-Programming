#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second 
using namespace std;

int main()
{
	int n, i=0, k, v;	
	set<pii>adj;
	int deg[200001]={};
	int seq[200001];
	queue <int>Q;
	bool ans=1;

	cin>>n;
	for (i = 0; i < n-1; ++i)
	{
		int a, b;
		cin>>a>>b;
		adj.insert({a,b});
		adj.insert({b,a});
		deg[b]++, deg[a]++;
	}

	for (i = 0; i < n; ++i)
	{
		cin>>seq[i];
	}

	i=0;
	Q.push(1);
	if(seq[0]!=1)
	{
		cout<<"No";
		exit(0);
	}
	while(i<n)
	{
		if(Q.empty())
		{
			break;
		}
		v=Q.front(); Q.pop();
		while(i<n-1)
		{
			auto it=adj.find({v,seq[++i]});
			if(it==adj.end())
				break;
			adj.erase(it);
			deg[v]--; deg[seq[i]]--;
			Q.push(seq[i]);
		}
		if(deg[v])
		{
			ans=0;
			break;
		}
		i--;
	}
	for(int d:deg)
		if(d)
			ans=0;
	if(ans)
		cout<<"Yes";
	else
		cout<<"No";
}