#include<iostream>
#define int long long
#define MOD 1000000007
using namespace std;

void matmul(int a[2][2], int b[2][2], int c[2][2])
{
	for(int i=0; i<2; ++i)
		for(int j=0; j<2; ++j)
		{
			c[i][j]=0;
			for(int k=0; k<2; ++k)
				c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%MOD)%MOD;
		}
}
void assign(int a[2][2], int b[2][2])
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			a[i][j]=b[i][j];
		}
	}
}
void power(int a[2][2], int n, int ans[2][2])
{
	if(n==1)
	{
		assign(ans, a);
		return;
	}
	power(a,n/2,ans);
	int temp[2][2]={}	;
	matmul(ans, ans, temp);
	assign(ans, temp);
	if(n%2)
	{
		matmul(ans, a, temp);
		assign(ans, temp);
	}
}

int32_t main()
{
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	int base[2]={0,1};
	int t[2][2]={{0,3},{1,2}};
	int ans[2][2]={};
	power(t,n-1,ans);
	cout<<ans[0][1]<<endl;
}	