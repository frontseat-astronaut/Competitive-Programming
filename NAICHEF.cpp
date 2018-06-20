#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N, A,B;
		cin>>N>>A>>B;

		map <int,int> dice;
		for(int i=0; i<N; ++i)
		{
			int x;
			cin>>x;
			++dice[x];
		}

		if(dice[A]==0)
		{
			printf("0\n");
			continue;
		}

		double P=(double)dice[A]*dice[B]/N/N;

		printf("%.10lf\n",P);
	}
}