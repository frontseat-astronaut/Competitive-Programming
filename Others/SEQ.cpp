#include<iostream>
#define MOD 1000000000
#define int long long
using namespace std;
int k;

void matmul(int A[11][11], int B[11][11], int C[11][11])
{
	for(int i=0; i<k; ++i)
	{
		for(int j=0; j<k; ++j)
		{
			for(int l=0; l<k; ++l)
			{
				C[i][j]=(C[i][j]+(A[i][l]*B[l][j])%MOD)%MOD;
			}
		}
	}
}
void assign(int A[11][11], int B[11][11])
{
	for(int i=0; i<k; ++i)
	{
		for(int j=0; j<k; ++j)
		{
			A[i][j]=B[i][j];
		}
	}
}
void display(int A[11][11])
{
	for(int i=0; i<k; ++i)
	{
		for(int j=0; j<k; ++j)
			cout<<A[i][j]<<'\t';
		cout<<endl;
	}
	cout<<endl;
}
void power(int A[11][11], int n, int ans[11][11])
{
	if(n==1)
	{
		assign(ans, A);
//		display(ans);
		return;
	}
	if(n%2==0)
	{
		power(A, n/2, ans);
		int temp[11][11]={};
		matmul(ans, ans, temp);
		assign(ans, temp);
//		display(ans);
	}
	else
	{
		power(A, (n-1)/2, ans);
		int temp1[11][11]={}, temp2[11][11]={};
		matmul(ans, ans, temp1);
		matmul(A, temp1, temp2);
		assign (ans, temp2);
//		display(ans);
	}
}

int32_t main()
{	
	int C;
	cin>>C;
	
	while(C--)
	{
		cin>>k;
		int b[11]={}, c[11]={}, n;
		int T[11][11]={};
		for (int i = 0; i < k; ++i)
		{
			cin>>b[i];
		}
		for (int i = 0; i < k; ++i)
		{
			cin>>c[i];
		}
		cin>>n;

		if(n<=k)
		{
			cout<<b[n-1]<<endl;
			continue;
		}

		for(int i=0; i<k; ++i)
			T[0][i]=c[i];
		for(int i=1; i<k; ++i)
		{
			for(int j=0; j<k; ++j)
			{
				if(j==i-1)
					T[i][j]=1;
				else
					T[i][j]=0;
			}
		}
		int ans[11][11]={};
		power(T, n-k, ans);
		int an=0;
		for(int i=0; i<k; ++i)
		{
			an=(an+(ans[0][i]*b[k-1-i])%MOD)%MOD;
		}
		cout<<an<<endl;

	}
}