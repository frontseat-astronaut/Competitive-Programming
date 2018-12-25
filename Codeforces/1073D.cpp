#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long 
using namespace __gnu_pbds; 
using namespace std;
int n, T;
const int N=200001;
int a[N<<1];
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> tr; 
void build()
{
	for(int i=n-1; i>0; --i)
		a[i]=a[i<<1]+a[i<<1|1];
}

void update(int j, int p)
{
	a[j+n]=p;
	for(int i=(j+n)>>1; i>0; i>>=1)
		a[i]=a[i<<1]+a[i<<1|1];
}

int query(int l, int r)
{
	int ret=0;
	for(l+=n, r+=n; l<r; l>>=1, r>>=1)
	{
		if(l&1)
			ret+=a[l++];
		if(r&1)
			ret+=a[--r];
	}
	return ret;
}

int binary_search(int T, int curr)
{
	int l=curr, r=n-1, mid, qm;
	int ans=n;
	while(l<=r)
	{
		mid=(l+r)>>1;
		qm=query(curr,mid+1);
		
		if(qm>T)
		{
			ans=mid;
			r=mid-1;
		}
		else 
		{
			l=mid+1;
		}
	}
	return ans;
}

int32_t main()
{
	int cnt=0, sum=0;
	tr ind;
	cin>>n>>T;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i+n];
		sum+=a[i+n];
		ind.insert(i);
	}
	build();
	int pos, curr;
	assert(sum>=0);
	while( sum && T)
	{
//	    cout<<T<<" "<<cnt<<endl;
		if(sum<=T)
		{
			cnt+=(T/sum)*(ind.size());
			T-=(T/sum)*sum;
			continue;
		}
		pos=0;
		while(pos<n)
		{
			curr=pos;
			pos=binary_search(T, curr);
			T-=query(curr, pos);
			cnt+=ind.order_of_key(pos)-ind.order_of_key(curr);
			if(pos==n)
			{
				break;
			}
			ind.erase(pos);
			sum-=a[pos+n];
			update(pos,0);
			pos++;
		}
	}
	cout<<cnt<<endl;	
}