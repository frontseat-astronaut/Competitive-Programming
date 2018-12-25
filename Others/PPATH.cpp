#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ff first
#define ss second
vector<int>primes;
vector<bool>isp(1e4+5, 1);
const int n=1061;

void sieve()
{
	for(int i=2; i<1e4+1; ++i)
	{
		if(isp[i])
		{
			if(i>=1000 && i<1e4)
			{
				primes.push_back(i);
			}
			for(int j=i; j*i<=1e4; ++j)
			{
				isp[j*i]=0;
			}
		}
	}
}
int digdiff(int p1, int p2)
{
	int change=0;
	for(int i=1; i<=4; i++)
	{
		if(p1%10!=p2%10)
			change++;
		p1/=10; p2/=10;
	}
	return change;
}

vector<int>adj[n];
void connect()
{
	for(int i=0; i<n; ++i)
	{
		for(int j=i+1; j<n; ++j)
		{
			if(digdiff(primes[i], primes[j])==1)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
}
int find(int p)
{
	for (int i = 0; i < n; ++i)
	{
		if(primes[i]==p)
			return i;
	}
}
int32_t main()
{
	sieve();
	connect();

	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin>>t;
	while(t--)
	{
		int p1, p2;
		cin>>p1>>p2;

		int s=find(p1), e=find(p2);

		bool visited[n]={};
		queue <pii> q;
		q.push({s, 0});
		pii x;
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			if(visited[x.ff])
				continue;
			if(x.ff==e)
				break;
			visited[x.ff]=1;
			for(auto y:adj[x.ff])
			{
				q.push({y,x.ss+1});
			}
		}
		cout<<x.ss<<"\n";
	}
}