#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

struct knight
{
	int p,id;
	long long c;
};

bool cmp(knight a, knight b)
{
	return a.p<b.p;
}

int main()
{
	int n,k;
	cin>>n>>k;

	knight K[n];
	map <long long,int> M;
	for(int i=0; i<n; ++i)
	{
		cin>>K[i].p;
		K[i].id=i;
	}
	for(int i=0; i<n; ++i)
	{
		cin>>K[i].c;
	}
	sort(K,K+n,cmp);

	long long ans[n]={};
	for(int i=0; i<n; ++i)
	{
		if(M.size())
		{
			auto it = M.rbegin();
			int kill_count=k;
			for(; it!=M.rend() && kill_count>0; ++it)
			{
				ans[K[i].id]+=(long long)(min(kill_count,(*it).second))*((*it).first);
				kill_count-=min(kill_count,(*it).second);	
//				cout<<(*it).first<<" ";			
			}
//			cout<<endl;
		}
		ans[K[i].id]+=(long long)K[i].c;
//		cout<<ans[K[i].id]<<" ";
		M[K[i].c]++;
/*
		for(auto it=M.begin(); it!=M.end(); ++it)
			cout<<(*it).first<<"["<<(*it).second<<"] ";
		cout<<endl;
*/
	}
	
	for(int i=0; i<n; ++i)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	
}