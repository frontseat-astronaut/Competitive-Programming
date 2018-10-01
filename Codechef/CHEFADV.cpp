#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,M,X,Y;
		cin>>N>>M>>X>>Y;
		int r1=(N-1)%X, r2=(M-1)%Y, r_1=(N-2)%X, r_2=(M-2)%Y;
		if(r1==0 && r2==0)
			cout<<"Chefirnemo"<<endl;
		else if((r_1==0 && r_2==0)&&(N>1 &&M>1))
			cout<<"Chefirnemo"<<endl;
		else
			cout<<"Pofik"<<endl;
	}
}