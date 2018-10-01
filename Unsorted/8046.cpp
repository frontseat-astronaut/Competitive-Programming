#include<iostream>
using namespace std;

struct photo
{
	int a,b;
};

bool cmp(photo a, photo b)
{
	if(a.a==b.a)
		return a.b<b.b;
	return a.a<b.a;
}

int main()
{
	int n,t;
	while(cin>>n>>t)
	{
		photo P[n];
		bool ans=true;
		for(int i=0; i<n; ++i)
		{
			cin>>P[i].a>>P[i].b;
			if(P[i].b-P[i].a+1<t)
				ans=false;
		}
		if(!ans) 
		{
			cout<<"no"<<endl;
			continue;
		}
		sort(P, P+n, cmp);
		int T=P[0].a;
		priority_queue <int> Q;

		for(int i=0; i<n; ++i)
		{
			if(P[i].b-T+1>=t)
			{
				T+=t;
				Q.push(P[i].b);
				continue;
			}
			while(P[i].b-T+1<t)
			{
				T-=Q.top();
				Q.pop();
			}
			
		}
	}
}
