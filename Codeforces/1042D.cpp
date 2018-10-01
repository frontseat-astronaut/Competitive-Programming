#include<bits/stdc++.h>
using namespace std;
int n;
int B[200001];
int tree[400001], c[400001];

void add(int node, int val)
{
	if(!c[node])
	{
		tree[node]=val;
		c[node]=1;
		return ;
	}
	if(val<tree[node])
	{
		add(node*2, val);
	}
	else 
		add(node*2+1,val);
}

void check(int node, int val)
{
	if(val>=tree[node])
	{
		if()
	}
}

int main()
{
	B[0]=0
	for (int i = 1; i < =n; ++i)
	{
		cin>>B[i];
		B[i]+=B[i-1];
	}
	for(int r=1; r<=n; ++r)
	{
		add()
	}
}