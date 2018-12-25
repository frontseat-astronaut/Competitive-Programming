#include<bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n>>k;
		vector<pii>X;
		for (int i = 1; i <= n; ++i)
		{
			int l, r;
			cin>>l>>r;
			X.pb({l, -i});
			X.pb({r, i});
		}
		sort(X.begin(), X.end());

		int ans=0, curr, cnt=0, add, sub, prev=X[0].f;
		for(int i=0; i<2*n; ++i)
		{
			curr=X[i].f;
			add=0, sub=0;
			while(X[i].f==curr && i<2*n)
			{
				if(X[i].s<0)
					add++;
				else
					sub++;
				++i;
			}
			i--;
			if(cnt==k)
				ans=max(ans, curr-prev);
			prev=curr;
			cnt+=add-sub;
		}
		cout<<ans<<endl;
	}
}