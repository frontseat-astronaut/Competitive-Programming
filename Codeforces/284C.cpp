#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
struct elem
{
	int val, add;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<elem>arr;
	arr.push_back({0,0});
	int N=1;
	long long sum=0, add=0;
	while(n--)
	{
		int t;
		cin>>t;
		if(t==1)
		{
			int a,x;
			cin>>a>>x;
			arr[a-1].add+=x;
			sum+=a*x;
			printf("%.6lf\n",(double)sum/N);
		}
		else if(t==2)
		{
			int k;
			cin>>k;
			arr.push_back({k,0});
			N++;
			sum+=k;
			printf("%.6lf\n",(double)sum/N);
		}
		else
		{
			sum-=arr[N-1].add+arr[N-1].val;
			arr[N-2].add+=arr[N-1].add;
			arr.pop_back();
			N--;
			printf("%.6lf\n",(double)sum/N);
		}
	}
}