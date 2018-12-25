#include<bits/stdc++.h>
using namespace std;

#define pff pair<double,double>
#define pfi pair<double, int>
#define v second
#define w first
#define pb push_back

bool loe(double x, double y)
{
	double d=y-x;
	if(d>0 || fabs(d)<10e-6)
		return 1;
	return 0;
}

double D(pff a, pff b)
{
	return sqrt((a.v-b.v)*(a.v-b.v)+(a.w-b.w)*(a.w-b.w));
}

bool dijkstra(vector<pfi>adj[], int n, double d)
{
	priority_queue <pfi> Q;
	double dist[n];
	for (int i = 0; i < n; ++i)
	{
		dist[i]=DBL_MAX;
	}
	dist[0]=0;
	Q.push({0,0});
	bool processed[n]={};
	while(!Q.empty())
	{
		int x=Q.top().v;
		Q.pop();
		if(processed[x])
			continue;
		processed[x]=1;
		for(auto y:adj[x])
		{
			if(dist[y.v]>dist[x]+y.w)
			{
				dist[y.v]=dist[x]+y.w;
				Q.push({-dist[y.v],y.v});	
			}
		}
	}
	if(loe(dist[n-1],d))
		return 1;
	else
		return 0;
}

int main()
{
	string W;
	while(1)
	{
		cin>>W;
		if(W=="*")
			break;
		int w=stoi(W);
		int h;
		cin>>h;

		int n;
		cin>>n;
		vector<pfi>adj[n+2];
		vector<pff> p;
		p.pb({0,0});
		for (int i = 1; i < n+1; ++i)
		{
			double x, y;
			cin>>x>>y;
			p.pb({x,y});
		}
		p.pb({w,h});
		double d;
		cin>>d;

		for(int i=0; i<n+2; ++i)
		{
			for(int j=i+1 ;j<n+2; ++j)
			{
				double dist=D(p[i], p[j]);
				if(loe(dist, 1.5))
				{
					adj[i].pb({ dist, j});
					adj[j].pb({ dist, i});
				}
			}
		}

		if(dijkstra(adj, n+2, d))
			cout<<"I am lucky!"<<endl;
		else
			cout<<"Boom!"<<endl;
	}
}