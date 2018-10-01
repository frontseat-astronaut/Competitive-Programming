#include<iostream>
#include<map>
using namespace std;
int main()
{
	string num;
	while(cin>>num)
	{
		if(num=="END")
			break;
		double x=stod(num);
//		cout<<x<<": ";
		bool flag=1;
		map<long long,bool>M;
		while(1)
		{
			if(M[x*10e6]) break;
			M[x*10e6]=1;
			x=x*3;
			int digit=(int)x;
			if(digit==1)
			{
				flag=0;
				break;
			}
			x=x-(int)x;
//			cout<<digit<<endl;
		}
		if(flag)
			cout<<"MEMBER"<<endl;
		else
			cout<<"NON-MEMBER"<<endl;
	}
}