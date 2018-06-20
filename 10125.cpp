#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main()
{
	while(true)
	{
		int N;
		cin>>N;
		if(!N)
			break;
		int arr[N];
		unordered_map <long long,int> sum,M;

		for(int i=0; i<N; ++i)
		{
			cin>>arr[i];
			M[arr[i]]++;
		}

		for(int i=0; i<N; ++i)
		{
			for(int j=i+1; j<N; ++j)
			{
				sum[arr[i] + arr[j]]++;
			}
		}

		long long max=-536870915;
		bool found=0;

		for(int i=0; i<N; ++i)
		{
			for(int j=i+1; j<N; ++j)
			{
				long long diff=arr[j]-arr[i];
				int temp=sum[diff];
				if(M[diff-arr[j]])
				{
					--sum[diff];
				}
				if(M[diff-arr[i]])
				{
					--sum[diff];
				}
				if(sum[diff]>0)
				{
					found=1;
					if(max<arr[j])
						max=arr[j];
				}

				diff=-diff;
				temp=sum[diff];
				if(M[diff-arr[j]])
				{
					--sum[diff];
				}
				if(M[diff-arr[i]])
				{
					--sum[diff];
				}
				if(sum[diff]>0)
				{
					found=1;
					if(max<arr[i])
						max=arr[i];
				}

			}
		}

		if(found)
			cout<<max<<endl;
		else
			cout<<"no solution"<<endl;
	}
}