#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;
#define int long long
int32_t main()
{
	int N, mask;
	cin>>N;
	unordered_map<int, int>bmap;
	set<int>masks;
	for (int i = 0; i < N; ++i)
	{
		string s;
		cin>>s;
		mask=0;
		for(auto ch:s)
		{
			mask^=(1<<(ch-'a'));
		}
		bmap[mask]++;
		masks.insert(mask);
	}
	int ans=0, self_pairs=0;
	for(auto m:masks)
	{
		self_pairs+=bmap[m]*(bmap[m]-1)/2;
		for(int j=1; j<(1<<26); j*=2)
		{
			ans+=bmap[m]*(bmap[m^j]);
		}
	}
	ans/=2;
	ans+=self_pairs;
	cout<<ans<<endl;

}