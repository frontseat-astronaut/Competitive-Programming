#include<iostream>
using namespace std;
int T, N, Q, L, R;
int A[100001];
int andtree[400005];
long long int cnttree[400005];
bool square[(1<<30)+1];

struct tree
{
	int AND, CNT;
};

void build(int node, int start, int end)
{
	if(start==end)
	{
		andtree[node]=A[start];
		if(square[A[start]])
			cnttree[node]++;
		return;
	}
	int mid=(start+end)/2;
	build(node*2, start, mid);
	build(node*2+1, mid+1, end);
	andtree[node]=andtree[node*2]&andtree[node*2+1];
	cnttree[node]=cnttree[node*2]+cnttree[node*2+1];
	if(square[andtree[node]])
	{
		cnttree[node]++;
	}
}

long long query(int node, int start, int end, int l, int r)
{
	if(l>end || r<start)
		return 0;
	if(l<=start && end<=r)
	{
		return cnttree[node];
	}
	int mid=(start+end)/2;
	long long p1=query(node*2, start, mid, l, r);
	long long p2=query(node*2+1, mid+1, end, l, r);
	return p1+p2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for(int i=0; i*i<=(1<<30)+1; ++i)
	{
		square[i*i]=1;
	}

	cin>>T;
	while(T--)
	{
		cin>>N>>Q;
		for(int i=0; i<N; ++i)
		{
			cin>>A[i];
		}

		build(1, 0, N-1);

		while(Q--)
		{
			cin>>L>>R;
			L--, R--;
			cout<<query(1,0,N-1,L,R)<<endl;

		}		
	}
}