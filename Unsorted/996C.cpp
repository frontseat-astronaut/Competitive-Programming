#include<iostream>
using namespace std;

struct car
{
	int r,c;
	int pr,pc;
};

int main()
{
	int n,k;
	cin>>n>>k;

	int grid[4][n];
	for(int i=0; i<4; ++i)
		for(int j=0; j<n; ++j)
			cin>>grid[i][j];

	car c[n+1];
	for(int i=0; i<n; ++i)
	{
		c[grid[0][i]].pr=0;
		c[grid[0][i]].pc=i;
		c[grid[3][i]].pr=3;
		c[grid[3][i]].pc=i;

		c[grid[1][i]].r=1;
		c[grid[1][i]].c=i;
		c[grid[2][i]].r=2;
		c[grid[2][i]].c=i;
	}

	
}