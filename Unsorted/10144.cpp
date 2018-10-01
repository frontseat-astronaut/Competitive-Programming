#include<iostream>
using namespace std;

string dac(int N)
{
	if(N==1)
	{
		return "((A0|B0)|(A0|B0))";
	}
	string A="A"+to_string(N-1);
	string B="B"+to_string(N-1);
	return "(("+A+"|"+B+")|("+dac(N-1)+"|(("+A+"|"+A+")|("+B+"|"+B+"))))";
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N;
		cin>>N;

		cout<<dac(N)<<endl;
		if(T) cout<<endl;
	}
}