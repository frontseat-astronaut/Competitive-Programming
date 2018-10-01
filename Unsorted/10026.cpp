#include<iostream>
#include<vector>
using namespace std;

struct job
{
	int T, S, id;
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N; 

		job J[N];
		for(int i=0; i<N; ++i)
		{
			cin>>J[i].T>>J[i].S;
			J[i].id=i+1;
		}

		vector<job>	P;
		long long time=0;
		long long fine=0;
		for(int i=0; i<N; ++i)
		{
			long long minm=J[i].S*time;
			int pos=i;
			for(long long j=i, S=0, T=time; ; )
			{
				long long sum=S*J[i].T+J[i].S*T;
				if(sum<minm)
				{
					minm=sum;
					pos=j;
				}
				--j;
				if(j<0) break;
				S+=P[j].S;
				T-=P[j].T;
			}
			auto it=P.begin()+pos;
			P.insert(it, J[i]);
			time+=J[i].T;
			fine+=J[i].S*time;
		}
//		cout<<"fine: "<<fine<<endl;
		cout<<P[0].id;
		for(int i=1; i<N; ++i)
		{
			cout<<" "<<P[i].id;
		}
		cout<<endl;
		if(t) cout<<endl;
	}
}