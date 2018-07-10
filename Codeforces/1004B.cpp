#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct visitor
{
	int l,r;
};

bool cmp(visitor a, visitor b)
{
	return (a.r-a.l)<(b.r-b.l);
}

int main()
{
	int n,m;
	cin>>n>>m;

	vector<visitor> V;
	for(int i=0; i<m; ++i)
	{
		int l,r;
		cin>>l>>r;
		V.push_back({l-1,r-1});
	}
	sort(V.begin(), V.end(), cmp);

	int g[n]={0};
	for(int i=0; i<n; ++i)
	{
		if(i%2==0) cout<<1;
		else cout<<0;
	}
	cout<<endl;

}