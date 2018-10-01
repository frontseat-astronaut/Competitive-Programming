#include<iostream>
#include<vector>
using namespace std;
vector<int>BIT(100001, 0);
void update(int x, int v)
{
	while(x>0 && x<=BIT.size())
	{
		BIT[x]+=v;
		x=x+(x&(-x));
	}
}
int sum(int x)
{
	int s=0;
	while(x>0)
	{
		s+=BIT[x];
		x=x-(x&(-x));
	}
	return s;
}
int findKthSmallest(int k)
{
	int l=1, r=BIT.size();
	int m;
	while(l<=r)
	{
		m=(l+r)/2;
		if(sum(m)<k)
		{
			l=m+1;
		}
		else
			r=m-1;
	}
	return m;
}
int findRank(int x)
{
	return sum(x);		
}
int main()
{
	int N=5;
	int arr[N]={1,1,7,9,10};
	for(int i=0; i<N; ++i)
	{
		update(arr[i],1);
	}
	cout<<findKthSmallest(3)<<endl;
	cout<<findRank(9)<<endl;
}