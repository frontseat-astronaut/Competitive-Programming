#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int r,c,n;
		cin>>r>>c>>n;

		char grid[2][r][c];
		for(int i=0; i<r; ++i)
			for(int j=0; j<c; ++j)
				cin>>grid[0][i][j];

		int g=0, k=0;
		for(k=0; k<n; ++k, g=(g+1)%2)
		{ 
			for(int i=0; i<r; ++i)
			{
				for(int j=0; j<c; ++j)
				{
					grid[!g][i][j]=grid[g][i][j];
					if(i+1<r)
					{
						if(grid[g][i][j]=='R' && grid[g][i+1][j]=='P')
							grid[!g][i][j]='P';
						else if(grid[g][i][j]=='P' && grid[g][i+1][j]=='S')
							grid[!g][i][j]='S';
						else if(grid[g][i][j]=='S' && grid[g][i+1][j]=='R')
							grid[!g][i][j]='R';
					}
					if(j+1<c)
					{
						if(grid[g][i][j]=='R' && grid[g][i][j+1]=='P')
							grid[!g][i][j]='P';
						else if(grid[g][i][j]=='P' && grid[g][i][j+1]=='S')
							grid[!g][i][j]='S';
						else if(grid[g][i][j]=='S' && grid[g][i][j+1]=='R')
							grid[!g][i][j]='R';
					}
					if(i-1>=0)
					{
						if(grid[g][i][j]=='R' && grid[g][i-1][j]=='P')
							grid[!g][i][j]='P';
						else if(grid[g][i][j]=='P' && grid[g][i-1][j]=='S')
							grid[!g][i][j]='S';
						else if(grid[g][i][j]=='S' && grid[g][i-1][j]=='R')
							grid[!g][i][j]='R';
					}
					if(j-1>=0)
					{
						if(grid[g][i][j]=='R' && grid[g][i][j-1]=='P')
							grid[!g][i][j]='P';
						else if(grid[g][i][j]=='P' && grid[g][i][j-1]=='S')
							grid[!g][i][j]='S';
						else if(grid[g][i][j]=='S' && grid[g][i][j-1]=='R')
							grid[!g][i][j]='R';
					}
				}
			}
		}
		
		for(int i=0; i<r; ++i)
		{
			for(int j=0; j<c; ++j)
				cout<<grid[g][i][j];
			cout<<endl;
		}
		if(t) cout<<endl;
		
	}
}