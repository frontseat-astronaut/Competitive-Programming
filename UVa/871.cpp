#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

char grid[25][26];
int C,R;

int f(int i, int j)
{
	if(i<R && i>=0 && j<C && j>=0)
	{
		if(grid[i][j]=='0') return 0;
		grid[i][j]='0';
		int top=f(i-1,j);
		int topright=f(i-1,j+1);
		int right=f(i,j+1);
		int bottomright=f(i+1,j+1);
		int bottom=f(i+1,j);
		int bottomleft=f(i+1,j-1);
		int left=f(i,j-1);
		int topleft=f(i-1,j-1);

		return top+topright+right+bottomright+bottom+bottomleft+left+topleft+1;
	}
	return 0;
}

int main()
{
	int T;
	cin>>T;
	char ch;
	ch=getchar();
	ch=getchar();
	while(T--)
	{
		R=0; 
		while(scanf("%[^\n]s",grid[R++])!=EOF)
		{
			ch=getchar();
			if(strlen(grid[R-1])==0) break;
		}
		R--;
	
		C=strlen(grid[0]);

		int max=0;
		for(int i=0; i<R; ++i)
		{
			for(int j=0; j<C; ++j)
			{
				int size=f(i,j);
				if(max<size)
					max=size;
			}
		}
		cout<<max<<endl;
		if(T) cout<<"\n";
	}
}