#include<iostream>
using namespace std;
int n;
long long f(int r, int c, long long g[2][100001], int t)
{
	if(c==n-1)
		return g[r][c]*t+g[!r][c]*(t+1);
	long long sum=0;
	for(int i=c; i<n; ++i)
	{
		sum+=g[r][i]*(i-c+t)+g[!r][i]*(t+2*(n-i)+i-c-1);
	}
	return max(sum, f(!r,c+1, g, t+2)+g[r][c]*t+g[!r][c]*(t+1));
}

int main()
{
	cin>>n;

	long long g[2][100001];
	for(int i=0; i<2; ++i)
	{
		for(int j=0; j<n; ++j)
			cin>>g[i][j];
	}

	cout<<f(0,0,g,0)<<endl;

}