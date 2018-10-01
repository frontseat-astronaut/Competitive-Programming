#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct trav
{
	string name;
	int balance;
};

bool cmp(trav a, trav b)
{
	return a.balance>b.balance;
}

int main()
{
	int n,t;
	int caseno=1;
	while(cin>>n>>t)
	{
		if(n==0) break;
		trav T[n];
		for(int i=0; i<n; ++i)
		{
			cin>>T[i].name;
			T[i].balance=0;
		}
		for(int i=0; i<t; ++i)
		{
			string from, to;
			int trans;
			cin>>from>>to>>trans;
			for(int j=0; j<n; ++j)
			{
				if(T[j].name==to)
				{
					T[j].balance+=trans;
				}
				if(T[j].name==from)
				{
					T[j].balance-=trans;
				}
			}
//			for(int j=0; j<n; ++j)
//				cout<<T[j].name<<": "<<T[j].balance<<"\t";
//			cout<<endl;
		}
		sort(T, T+n, cmp);

		cout<<"Case #"<<caseno++<<endl;

		if(T[n-1].balance!=T[0].balance)
			for(int i=0; i<n-1; ++i)
			{
				T[i+1].balance+=T[i].balance;
				cout<<T[i].name<<" "<<T[i+1].name<<" "<<T[i].balance<<endl;
				T[i].balance=0;
			}
		cout<<endl;
	}
}