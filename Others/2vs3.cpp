#include<iostream>
using namespace std;
string S;
int tree[400001];
void build(int n, int s, int e)
{
	if(s==e)
	{
		tree[n]=S[s]-'0';
		return ;
	}
	int mid=(s+e)/2;
	build(2*n, s, mid);
	build(2*n+1, mid+1, e);
	tree[n]=( tree[2*n]*((e-mid)%2+1) + tree[2*n+1])%3;
}

void update(int n, int s, int e, int l)
{
	if(s==e)
	{
		tree[n]=1;
		return ;
	}
	int mid=(s+e)/2;
	if(l<=mid)
	{
		update(2*n, s, mid, l);
	}
	else
		update(2*n+1, mid+1, e, l);
	tree[n]=( tree[2*n]*((e-mid)%2+1) + tree[2*n+1])%3;
}

int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        return 0;
    }
    if(l <= start and end <= r)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    if(r<=mid)
        return p1;
    if(mid<l)
        return p2;
    return (p1*((min(r,end)-mid)%2+1) + p2)%3;
}

int main()
{
	int N;
	cin>>N;

	cin>>S;

	build(1,0, N-1);

	int Q;
	cin>>Q;
	while(Q--)
	{
		int q;
		cin>>q;
		if(q==0)
		{
			int l, r;
			cin>>l>>r;
			cout<<query(1, 0, N-1, l, r)<<endl;

		}
		else
		{
			int l;
			cin>>l;
			update(1, 0, N-1, l);
		}
	}
}