#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{	int n,k;
	cin>>n>>k;
	int l=1, r=k;
	int cnt=0;
	std::random_device rd;
    std::mt19937 mt(rd());
    uniform_int_distribution<> dis(1,ceil((double)n/k));
    uniform_int_distribution<> d(0,k-1);

	while(cnt<4500)
	{
		int i=dis(mt);
		l=(i-1)*k+1, r=min(i*k+1,n);
		cout<<l<<" "<<r<<endl;
		cout.flush();
		string resp;
		cin>>resp;
		if(resp=="Yes")
		{
			int 
				int j=d(mt);
				while(l+j>n)
				{
					j=d(mt);
				}
				cout<<l+j<<" "<<l+j<<endl;
				cout.flush();
				cin>>resp;
				if(resp=="Yes")
					return 0;
		}
		++cnt;
	}
}