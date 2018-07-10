#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	map <int,int> m;
	unordered_map <int,bool> rep;
	for(int i=0; i<n; ++i)
	{
		cin>>a[i];
		m[a[i]]++;
	}

	long long ans=0;
	for(int i=0; i<n-1; ++i)
	{		
		m[a[i]]--;
		if(m[a[i]]==0)
		{
			auto it=m.find(a[i]);
			m.erase(it);
		}
		if(rep[a[i]]) continue;
		ans+=m.size();
		rep[a[i]]=1;
//		cout<<m.size()<<endl;
		
	}
	cout<<ans<<endl;

}