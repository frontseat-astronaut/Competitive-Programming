#include<bits/stdc++.h>
using namespace std;
#define int unsigned int

int n, m, N, cc;
int a[(1<<22)|1];
// map<int,int>ind;
bool visited1[(1<<22)|1], visited2[(1<<22)|1], present[(1<<22)|1];

int comp(int x)
{
	int y=0;
	for(int j=1; j<N; j<<=1)
	{
		if(!(x&j))
			y|=j;
	}
	return y;
}
void adja(int);
void dfs(int);
int32_t main()
{
	cin>>n>>m;
	N=1<<n;
	for (int i = 1; i < m+1; ++i)
	{
		cin>>a[i];
		present[a[i]]=1;
	}
	for(int i=1; i<m+1; ++i)
	{
		if(!visited1[a[i]])
		{
			// cout<<a[i]<<":";
			cc++;
			visited1[a[i]]=1;
			dfs(a[i]);
			// cout<<"\n";
		}
	}
	// cout<<comp(5)<<endl;
	cout<<cc;
}
void adja(int x)
{
	for(int j=1; j<N; j<<=1)
	{
		if(!(j&x))
		{
			dfs(x|j);
		}
	}
}
void dfs(int x)
{
	if(visited2[x])
		return;
	visited2[x]=1;
	visited1[comp(x)]=1;
	// cout<<comp(x)<<" ";
	adja(x);
	if(present[comp(x)])
		dfs(comp(x));
}