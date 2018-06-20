#include<iostream>
using namespace std;
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		long long x,y;
		cin>>x>>y;	

		long long count=0, length=1;
		for(long long i=x; i<y;)
		{
	//		cout<<i<<" ";
			if(i==x)
			{
				i++;
				count++;
				continue;
			}
			if(y-i>=(length+1)*(length+2)/2)
			{
				i+=length+1;	
				count++;
				length++;
			}
			else if(y-i>=length*(length+1)/2)
			{
				i+=length;
				count++;
			}
			else
			{
				i+=length-1;
				++count;
				length--;
			}
		}
	//	cout<<endl;
		cout<<count<<endl;
	}
}