#include<iostream>
#include<set>
#include<algorithm>
#define int long long
using namespace std;

int32_t main()
{
	int n;
	cin>>n;
	int Sn=n*(n+1)/2, i;
	bool flag=0; 
	for( i=1; 2*i<=Sn; ++i)
	{
		if(__gcd(i,Sn-i)>1)
		{
//			cout<<i<<" "<<Sn-i<< endl;
			int sum=0, j=1;
			set<int>P1, P2;
			do
			{
				sum+=j;
				P1.insert(j);
				++j;
			}
			while(sum<=i);
			if(sum!=i)
				P1.erase(sum-i);
			for(j = 1; j<=n; ++j)
			{
				if(P1.find(j)==P1.end())
					P2.insert(j);
			}
			if(P1.size()*P2.size()==0)
			{
				continue;
			}
			cout<<"Yes"<<endl;
			cout<<P1.size()<<" ";
			for(auto p1:P1)
				cout<<p1<<" ";
			cout<<endl;
			cout<<P2.size()<<" ";
			for(auto p2:P2)
				cout<<p2<<" ";
			cout<<endl;
			flag=1;
			break;
		}
	}
	if(!flag)
		cout<<"No"<<endl;

	
}