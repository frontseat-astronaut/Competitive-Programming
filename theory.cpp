#include<iostream>
using namespace std;

int main()
{
	int arr[5]={3,6,1,7,2};
	int num=10, n=5;
	int sum=0;

	for(int i=-1, j=0; j<=5; )
	{
		if(sum<num)
		{
			sum+=arr[j++];
		}
		else if(sum>num)
		{
			sum-=arr[++i];
		}
		else
		{
			cout<<'['<<i+1<<","<<j-1<<"]"<<endl;
			sum+=arr[j++];
		}
	}

}