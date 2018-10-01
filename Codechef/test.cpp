#include<bits/stdc++.h>
using namespace std;

int main()
{
	srand(time(NULL));
	int T=1;
	cout<<T<<endl;
	const int N=10, M=10;
	int Q=0;
	bitset<N>X;
	bitset<M>Y;
	for(int i=0; i<N; ++i)
	{
		X[i]=rand()%2;
	}
	for(int i=0; i<M; ++i)
	{
		Y[i]=rand()%2;
	}
	cout<<X<<" "<<Y<<endl;
	cout<<Q<<endl;
	int x,y;
	while(Q--)
	{
		x=rand()%N+1;
		y=rand()%M+1;
		cout<<x<<" "<<y<<endl;
	}
}