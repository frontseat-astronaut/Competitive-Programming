#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

int32_t main()
{
	int n;
	cin>>n;
	int P[2][n];
	int sum[2]={};
	for(int i=0; i<n; ++i)
	{
		cin>>P[0][i];
		sum[0]+=P[0][i];
	}
	sort(P[0],P[0]+n);
	for(int i=0; i<n; ++i)
	{
		cin>>P[1][i];
		sum[1]+=P[1][i];
	}
	sort(P[1],P[1]+n);
	int k[2]={n-1,n-1}; 
	int score[2]={0};
	bool p=0;
	while(!(k[0]<0 && k[1]<0))
	{
		if((sum[p]+score[p]>sum[(p+1)%2]+score[(p+1)%2] && k[p]>=0) ||(k[(p+1)%2]<0))
		{
			sum[p]-=P[p][k[p]];
			score[p]+=P[p][k[p]];
			k[p]--;
		}
		else 
		{
			sum[(p+1)%2]-=P[(p+1)%2][k[(p+1)%2]];
			k[(p+1)%2]--;
		}
		p=(p+1)%2;
	}
	cout<<score[0]-score[1]<<endl;
}