#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

string add(string num, char dig)
{
	int L=num.size();

	int sum=num[0]-'0'+dig-'0';
	int carry=sum/10;
	num[0]=(sum%10)+'0';

	for(int i=1; i<L; ++i)
	{
		sum=num[i]-'0'+carry;
		carry=sum/10;
		num[i]=sum%10+'0';
		if(carry==0) break;
	}

	if(carry)
		num.append(to_string(carry));	
	return num;
}	

int f(string N)
{
	if(N=="9")
		return 1;
	else if(N.length()==1)
		return 0;

	string sum="0";
	for(auto dig:N)
	{
		sum=add(sum,dig);
	}
//	cout<<sum<<endl;
	int next=f(sum);
	if(next==0)
		return 0;
	return 1+next;
}

int main()
{
	while(true)
	{
		string N;
		cin>>N;
		if(N=="0") break;

		string sum="0";
		for(auto dig:N)
		{
			sum=add(sum,dig);
		}

		int F=f(sum);
//		cout<<F<<endl;
		
		if(F)
		{
			printf("%s is a multiple of 9 and has 9-degree %d.\n",N.c_str(),F);
		}
		else
			printf("%s is not a multiple of 9.\n",N.c_str());
		

	}
}