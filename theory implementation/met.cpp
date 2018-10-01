#include<iostream>
using namespace std;

void multiply(int a[10][10], int b[10][10], int c[10][10], int k)
{
	for(int i=0; i<k; ++i)
	{
		for(int j=0; j<k; ++j)
		{
			c[i][j]=0;
			for(int l=0; l<k; ++l)
			{
				c[i][j]+=a[i][l]*b[l][j];
			}
		}
	}
}



int main()
{
	int n;
}