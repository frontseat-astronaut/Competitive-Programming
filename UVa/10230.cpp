#include<iostream>
#include<math.h>
using namespace std;

int N,X,Y;
char g[(int)pow(2,10)][(int)pow(2,10)];

char scan(int x[3], int y[3])
{
	bool ch_map[256]={0};
	int n=pow(2,N);
	for(int i=0; i<3; ++i)
	{
		if(y[i]>0)
			ch_map[ g[ y[i]-1 ][ x[i] ] ]=1;
		if(y[i]<n-1)
			ch_map[ g[ y[i]+1 ][ x[i] ] ]=1;
		if(x[i]>0)
			ch_map[ g[ y[i] ][ x[i]-1 ] ]=1;
		if(x[i]<n-1)
			ch_map[ g[ y[i] ][ x[i]+1 ] ]=1;
		if(y[i]>0 && x[i]>0)
			ch_map[ g[ y[i]-1 ][ x[i]-1 ] ]=1;
		if(y[i]<n-1 && x[i]>0)
			ch_map[ g[ y[i]+1 ][ x[i]-1 ] ]=1;
		if(y[i]>0 && x[i]<n-1)
			ch_map[ g[ y[i]-1 ][ x[i]+1 ] ]=1;
		if(y[i]<n-1 && x[i]<n-1)
			ch_map[ g[ y[i]+1 ][ x[i]+1 ] ]=1;							
	}
	for(char i='a'; i<='z'; ++i)
		if(!ch_map[i])
			return i;
}

void place(int r, int c, int quad)
{
	int x[3], y[3];
	if(quad==0)
	{
		x[0]=c+1; y[0]=r;
		x[1]=c+1; y[1]=r+1;
		x[2]=c; y[2]=r+1;
	}
	else if(quad==1)
	{
		x[0]=c; y[0]=r;
		x[1]=c+1; y[1]=r+1;
		x[2]=c; y[2]=r+1;
	}
	else if(quad==2)
	{
		x[0]=c+1; y[0]=r;
		x[1]=c; y[1]=r;
		x[2]=c; y[2]=r+1;
	}
	else
	{
		x[0]=c+1; y[0]=r;
		x[1]=c+1; y[1]=r+1;
		x[2]=c; y[2]=r;
	}
	for(int i=0; i<3; ++i)
		g[y[i]][x[i]]=',';
	char ch=scan(x,y);
	for(int i=0; i<3; ++i)
		g[y[i]][x[i]]=ch;
}

void L(int n, int r, int c, int y, int x)
{
	if(n==1) return;
	int quad;
//	cout<<x<<" "<<y<<endl;
	if(y<r+n/2 && x<c+n/2)
	{
		quad=0;
//		cout<<n<<" "<<quad<<endl;
		place(r+n/2-1, c+n/2-1, quad);
		L(n/2, r, c, y, x);
		L(n/2, r, c+n/2, r+n/2-1, c+n/2);
		L(n/2, r+n/2, c+n/2, r+n/2, c+n/2);
		L(n/2, r+n/2, c, r+n/2, c+n/2-1);
	}
	else if(y<r+n/2 && x>=c+n/2)
	{
		quad=1;
//		cout<<n<<" "<<quad<<endl;
		place(r+n/2-1, c+n/2-1, quad);
		L(n/2, r, c, r+n/2-1, c+n/2-1);
		L(n/2, r, c+n/2, y, x);
		L(n/2, r+n/2, c+n/2, r+n/2, c+n/2);
		L(n/2, r+n/2, c, r+n/2, c+n/2-1);
	}
	else if(y>=r+n/2 && x>=c+n/2) 
	{
		quad=2;
//		cout<<n<<" "<<quad<<endl;
		place(r+n/2-1, c+n/2-1, quad);
		L(n/2, r, c, r+n/2-1, c+n/2-1);
		L(n/2, r, c+n/2, r+n/2-1, c+n/2);
		L(n/2, r+n/2, c+n/2, y, x);
		L(n/2, r+n/2, c, r+n/2, c+n/2-1);
	}
	else
	{
		quad=3;
//		cout<<n<<" "<<quad<<endl;
		place(r+n/2-1, c+n/2-1, quad);
		L(n/2, r, c, r+n/2-1, c+n/2-1);
		L(n/2, r, c+n/2, r+n/2-1, c+n/2);
		L(n/2, r+n/2, c+n/2, r+n/2, c+n/2);
		L(n/2, r+n/2, c, y, x);
	}

}

int main()
{
	while(cin>>N)
	{
		cin>>X>>Y;

		int n=pow(2,N);
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
				g[i][j]=0;
		}

		g[Y-1][X-1]='*';

		L(n,0,0,Y-1,X-1);

		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
				cout<<g[i][j];
			cout<<endl;
		}
		cout<<endl;
	}
}