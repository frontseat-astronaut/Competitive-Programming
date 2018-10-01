#include<bits/stdc++.h>
using namespace std;
int tree[1000001];
int lazy[1000001];
string S;
void build(int node, int s, int e)
{
	if(s==e)
	{
		tree[node]=(S[s]=='>');
		return ;
	}
	int m=(s+e)/2;
	build(2*node, s, m);
	build(2*node+1, m+1, e);
	tree[node]=tree[2*node]+tree[2*node+1];
}
void update(int node, int s, int e, int l, int r)
{
	if(lazy[node])
	{
	    tree[node]=(e-s+1)-tree[node];
	    if(s!=e)
	    {
	        lazy[2*node]=1-lazy[2*node];
	        lazy[2*node+1]=1-lazy[2*node+1];
	    }
	    lazy[node]=0;
	}
	if(s>r || e<l || s>e)
		return ;
	if(l<=s && e<=r)
	{
	    tree[node]=(e-s+1)-tree[node];
	    if(s!=e)
	    {
	        lazy[2*node]=1-lazy[2*node];
	        lazy[2*node+1]=1-lazy[2*node+1];
	    }
		return;
	}
	int m=(s+e)/2;
	update(2*node, s, m, l, r);
	update(2*node+1, m+1, e, l, r);
	tree[node]=tree[2*node]+tree[2*node+1];
}
int query(int node, int s, int e, int l, int r)
{
	if(s>r || e<l)
		return 0;
	if(lazy[node])
	{
	    tree[node]=(e-s+1)-tree[node];
	    if(s!=e)
	    {
	        lazy[2*node]=1-lazy[2*node];
	        lazy[2*node+1]=1-lazy[2*node+1];
	    }
	    lazy[node]=0;
	}
	if(l<=s && e<=r)
	{
		return tree[node];
	}
	int m=(s+e)/2;
	int p1=query(2*node, s, m, l, r);
	int p2=query(2*node+1, m+1, e, l, r);
	return p1+p2;
}
int main()
{
	int N, M;
	cin>>N>>M;
	cin>>S;
	build(1,0,N-2);
	while(M--)
	{
		int q;
		cin>>q;
		if(q==1)
		{
			int l, r;
			cin>>l>>r;
			update(1, 0, N-2,l-1,r-2);
			cout<<tree[1]<<endl;
		}
		else
		{
			int f, t;
			cin>>f>>t;
			if(f==t)
			{
				cout<<0<<endl;
			}
			else if(f<t)
			{
				cout<<(t-f)-query(1, 0, N-2, f-1, t-2)<<endl;
			}
			else
			{
				cout<<query(1, 0, N-2, t-1, f-2)<<endl;
			}
		}
	}

}