#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

struct word
{
	char w[101];
	int e;
};
word W[101];

bool cmp(pair<int,int> a, pair<int,int> b)
{
	if(a.second==b.second)
		return W[a.first].e>W[b.first].e;
	else
		return a.second>b.second;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;

		for(int i=0; i<N; ++i)
		{
			cin>>W[i].w;
		}
		vector<pair<int,int>>adj[N];
		for(int i=0; i<N; ++i)
		{
			W[i].e=0;
			for(int j=0; j<N; ++j)
			{
				if(j==i) continue;
				int k=0; 
				while(W[i].w[k]==W[j].w[k] && k<strlen(W[i].w) && k<strlen(W[j].w))
					++k;
				adj[i].push_back({j,k});
				W[i].e+=k;
			}
		}
		for(int i=0; i<N; ++i)
		{
			sort(adj[i].begin(), adj[i].end(), cmp);
//			for(auto x:adj[i])
//				cout<<x.first<<" ";
//			cout<<endl;
		}

		int id=0;
		bool done[N]={};
		int ans=strlen(W[0].w);
		char* names[N];
		int i=0;
		while(true)
		{
			done[id]=1;
			names[i++]=W[id].w;
			pair<int,int> maxw;
			bool found=false;
			for(auto adjwo: adj[id])
			{
				if(!done[adjwo.first])
				{
					maxw=adjwo;
					found=1;
					break;
				}
			}
			if(!found) break;
			ans+=max(0,(int)strlen(W[maxw.first].w)-maxw.second);
			id=maxw.first;
		}
		cout<<ans<<endl;
		for(int i=0; i<N; ++i)
		{
			cout<<names[i]<<endl;
		}
	}
}