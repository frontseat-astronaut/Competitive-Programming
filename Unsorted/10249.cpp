#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

struct table
{
	int id, cap;
};

struct team
{
	int id, no;
	set<int>S;
};

bool cmptab(table a, table b)
{
	return a.cap<b.cap;
}
bool cmpteam(team a, team b)
{
	return a.no>b.no;
}
bool cmpid(team a, team b)
{
	return a.id<b.id;
}

int main()
{
	int M, N;
	while(cin>>M>>N)
	{
		if (M==0) break;
		team m[M];
		table n[N];

		for(int i=0; i<M; ++i)
		{
			cin>>m[i].no;
			m[i].id=i+1;
		}
		for(int i=0; i<N; ++i)
		{
			cin>>n[i].cap;
			n[i].id=i+1;
		}

		sort(n, n+N, cmptab);

		for(int i=0; i<N; ++i)
		{
			sort(m, m+M, cmpteam);
			for(int j=0; j<M && m[j].no>0 && j<n[i].cap; ++j)
			{
				m[j].S.insert(n[i].id);
				m[j].no--;
			}
		}
		bool flag=true;
		for(int j=0; j<M; ++j)
			if(m[j].no)
			{
				flag=false;
				break;
			}
		if(!flag)
		{
			cout<<0<<endl;
			continue;
		}
		cout<<1<<endl;
		sort(m, m+M, cmpid);
		for(int i=0; i<M; ++i)
		{
			for(auto t:m[i].S)
				cout<<t<<" ";
			cout<<endl;
		}
	}
}