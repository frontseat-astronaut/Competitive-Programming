#include<bits/stdc++.h>
using namespace std;
#define pipii pair<int,pair<int,int>>
#define pii pair<int,int>
#define ff first
#define ss second

char ch;
map<string, int>ind;
vector<vector<pipii>>adj;
int cnt=0;
vector<pipii>tmp;
pii ans;

bool dfs(int curr, int e, pii a, bool v[])
{
	if(curr==e)
	{
		ans=a;
		return 1;
	}
	v[curr]=1;
	for(auto y:adj[ curr ])
	{
		if(!v[ y.ff ])
		{
			if(dfs(y.ff, e, {a.ff*y.ss.ff, a.ss*y.ss.ss}, v))
				return 1;
		}
	}
	return 0;
}

int main()
{
	while(1)
	{
		cin>>ch;
		if(ch=='.')
			break;
		if(ch=='!')
		{
			int val1, val2;
			string obj1, obj2;
			cin>>val1>>obj1>>ch>>val2>>obj2;

			if(ind.find(obj1)==ind.end())
			{
				ind.insert({obj1, cnt++});
				adj.push_back(tmp);
			}
			if(ind.find(obj2)==ind.end())
			{
				ind.insert({obj2, cnt++});
				adj.push_back(tmp);
			}
			
			adj[ind[obj1]].push_back({ind[obj2], {val1,val2}});
			adj[ind[obj2]].push_back({ind[obj1], {val2,val1}});
		}
		else
		{
			string obj1, obj2;
			ans={0,0};
			bool visited[cnt]={};
			cin>>obj1>>ch>>obj2;

			if(!dfs(ind[obj1], ind[obj2], {1,1}, visited))
			{
				cout<<"? "<<obj1<<" = "<<"? "<<obj2<<endl;
			}
			else
			{
				int g=__gcd(ans.ff, ans.ss);
				ans.ff/=g; ans.ss/=g;
				cout<<ans.ff<<" "<<obj1<<" = "<<ans.ss<<" "<<obj2<<endl;
			}
		}
	}
}