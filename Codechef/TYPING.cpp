#include<bits/stdc++.h>
using namespace std;
#define int long long
struct cmp
{
	bool operator()(const string &a, const string &b)
	{
		return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
	}
};
int32_t main(){
	int T;
	cin>>T;
	bool h[256];
	h['d']=h['f']=0;
	h['j']=h['k']=1;
	int prev;
	while(T--)
	{
		int N, m;
		cin>>N;
		map<string, int, cmp>w;
		double ans=0, t;
		string wo;
		while(N--)
		{
			cin>>wo;
			m=w[wo];
			if(m)
			{
				ans+=m/2;
				continue;
			}
			t=0;
			prev=-1;
			for(auto ch:wo)
			{
				if(h[ch]==prev)
					t+=4;
				else
					t+=2;
				prev=h[ch];
			}
			w[wo]=t;
			ans+=t;
		}
		cout<<ans<<endl;
	}
}