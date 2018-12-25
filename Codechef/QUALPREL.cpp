#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,K;
		cin>>N>>K;
		int S[N];
		for (int i = 0; i < N; ++i)
		{
			cin>>S[i];
		}
		sort(S,S+N);
		int i=N-1;
		int cnt=0;
		while(i>=0)
		{
			if(cnt>=K)
				break;
			int temp=S[i];
			while(S[i]==temp && i>=0)
			{
				cnt++;
				--i;
			}
		}
		cout<<cnt<<endl;
	}
}