#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#include <iostream> 
#include<unordered_map>

#define pii pair<int,int>
using namespace __gnu_pbds; 
using namespace std;
struct robot
{
	int x,r,q,id;
};
bool cmpr(robot a, robot b)
{
	return a.r<b.r;
}
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //sorted by x

unordered_map<int, ordered_set>IQ;
vector<robot>R;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int N, K, x, r, q, id;

	cin>>N>>K;
	for(id=0; id<N; ++id)
	{
		cin>>x>>r>>q;
		IQ[q].insert({x, id+1});
		R.push_back({x,r,q,id+1});
	}
	sort(R.begin(),R.end(),cmpr);
	long long ans=0;
	for(auto rob:R)
	{
		r=rob.r;
		q=rob.q;
		x=rob.x;
        id=rob.id;
		IQ[q].erase({x,id});
		int right=IQ[q].order_of_key({x+r+1, -1});
		int left=IQ[q].order_of_key({x-r, -1});
		ans+=right-left;

		for(int k=1; k<=K; ++k)
		{
			if(IQ.find(q-k)!=IQ.end())
			{
				int right=IQ[q-k].order_of_key({x+r+1, -1});
        		int left=IQ[q-k].order_of_key({x-r, -1});
        		ans+=right-left;
			}
			if(IQ.find(q+k)!=IQ.end())
			{
				int right=IQ[q+k].order_of_key({x+r+1, -1});
		        int left=IQ[q+k].order_of_key({x-r, -1});
		        ans+=right-left;
			}
		}
	}
	cout<<ans<<endl;
}