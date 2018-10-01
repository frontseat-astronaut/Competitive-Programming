#include<iostream>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N, X, S;
		cin>>N>>X>>S;
		while(S--)
		{
			int a, b;
			cin>>a>>b;
			if(X==a)
				X=b;
			else if(X==b)
				X=a;
		}
		cout<<X<<endl;
	}
}