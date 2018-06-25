#include<iostream>
using namespace std;

int main()
{
	int A,B,C,N;
	cin>>A>>B>>C>>N;

	if(A<C||B<C||A+B<C)
	{
		cout<<-1<<endl;
	}
	else if (N==0)
		cout<<-1<<endl;
	else if(A+B-C>=N)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<N-A-B+C<<endl;
	}
}