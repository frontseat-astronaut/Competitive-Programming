#include<iostream>
using namespace std;

int main()
{
	int N;
	cin>>N;
	switch(N)
	{
		case 1:
				cout<<1<<endl<<1<<endl;
				break;
		case 2:
				cout<<"1 2\n1 2\n";
				break;
		case 3: 
				cout<<"2 3 1\n3 2 1\n";
				break;
	}
	int p1=N-N/2;
	for(int i=2; i<=p1; ++i)
		cout<<i<<" ";
	cout<<1<<" ";
	for(int i=p1+2; i<=N; ++i)
		cout<<i<<" ";
	cout<<p1+1<<endl;
	
	cout<<N;
	for(int i=1; i<N; ++i)
		cout<<" "<<i;
	cout<<endl;

}