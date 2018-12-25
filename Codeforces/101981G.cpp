#include<bits/stdc++.h>
#define int long long
using namespace std;
int m=1000000007;
int T[5][5]={
	{3, -3, 1, 1, 1},
	{1, 0, 0, 0, 0},
	{0, 1, 0, 0, 0},
	{0, 0, 0, 1, 1},
	{0, 0, 0, 0, 1}
};
int I[5][5]={
	{1, 0, 0, 0, 0},
	{0, 1, 0, 0, 0},
	{0, 0, 1, 0, 0},
	{0, 0, 0, 1, 0},
	{0, 0, 0, 0, 1}
};
int a3[5]={15, 5, 1, 3, 1};

void matmul(int c[5][5], int a[5][5], int b[5][5])
{
	for(int i=0; i<5; ++i)
	{
		for(int j=0; j<5; ++j)
		{
			c[i][j]=0;
			for(int k=0; k<5; ++k)
			{
				c[i][j]=(c[i][j] + (a[i][k]*b[k][j])%m+m)%m;
			}
		}
	}
}

void assign(int a[5][5], int b[5][5])
{
	for(int i=0; i<5; ++i)
		for(int j=0; j<5; ++j)
			a[i][j]=b[i][j];
}

void powr(int a[5][5], int r)
{
	if(r==0)
	{
		assign(a, I);
		return ;
	}
	powr(a, r>>1);
	int tmp[5][5];
	matmul(tmp, a, a);
	assign(a, tmp);
	if(r&1)
	{
		matmul(tmp, T, a);
		assign(a, tmp);
	}
}
int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n, an=0;
		cin>>n;
		if(n<=3)
		{
			cout<<a3[3-n]<<endl;
			continue;
		}

		int ans[5][5];
		assign(ans, I);
		powr(ans, n-3);
		for(int i=0; i<5; ++i)
		{
			an=(an+(ans[0][i]*a3[i])%m +m )%m;
		}
		cout<<an<<"\n";
	}
}