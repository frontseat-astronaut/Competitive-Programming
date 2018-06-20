#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

char land[50][50];
int x,y;

struct lake 
{
	int size;
	char ch;
};

int f(int i, int j, char ch)
{
	if(i<=x && i>=0 && j<=y && j>=0 )
	{
		if( land[i][j]!=ch) return 0;
		land[i][j]='.';
		int right=f(i,j+1,ch);
		int left=f(i,j-1,ch);
		int down=f(i+1,j,ch);
		int up=f(i-1,j,ch);
		return right+left+down+up+1;
	}
	return 0;
}

bool cmp(lake a, lake b)
{
	if(a.size==b.size)
		return a.ch<b.ch;
	else
		return a.size>b.size;
}

int main()
{
	int caseno=1;
	while(true)
	{
		cin>>x>>y;
		if(x==0)
			break;

		vector<lake>L;

		for(int i=0; i<x; ++i)
		{
			for(int j=0; j<y; ++j)
				cin>>land[i][j];
		}

		for(int i=0; i<x; ++i)
		{
			for(int j=0; j<y; ++j)
			{
				if(land[i][j]!='.')
				{
					char temp =land[i][j];
					L.push_back({f(i,j, temp),temp});	
				}
			}
		}
		sort(L.begin(),L.end(),cmp);
		cout<<"Problem "<<caseno++<<":\n";

		for(auto l:L)
			cout<<l.ch<<" "<<l.size<<endl;	

	}
}