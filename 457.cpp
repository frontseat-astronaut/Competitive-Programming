#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int DNA[10];
		for(int i=0; i<10; ++i)
			cin>>DNA[i];
		char map[4]={' ','.','x','W'};
		int culture[2][42]={};
		culture[0][20]=1;
		int c=0;

		for(int j=1; j<=40; ++j)
			cout<<map[ culture[c][j] ];
		cout<<endl;

		for(int i=0; i<49; ++i)
		{
			for(int j=1; j<=40; ++j)
			{
				culture[!c][j]=DNA[ culture[c][j+1]+culture[c][j-1]+culture[c][j] ];
				cout<<map[ culture[!c][j] ];
			}
			c=!c;
			cout<<endl;
		}
		if(t) cout<<endl;
	}
}