#include<iostream>
#include<string.h>
using namespace std;

int divby2(char num[80])
{
	char div[80];
	int k=0, r=0;
	int L=strlen(num);
    for(int i=0; i<L; ++i)
    {
    	int digit=num[i]-'0';
    	r=10*r+digit;
    	int q=r/2;
    	if(q==0 && k==0 && i+1!=L)
    	{
    		r=10*r+num[++i]-'0';
    		q=r/2;
    	}
    	div[k++]=q+'0';
    	r=r-2*q;
    }
    div[k]='\0';
    strcpy(num,div);
   	return r;
}

int main()
{
	int n,x,y;
	while(cin>>n)
	{
		bool world[n][n];

		char c[80];
		bool binary[257]={};
		int k=0;
		cin>>c;
		while(strcmp(c,"0"))
		{
			binary[k++]=divby2(c);
		}
/*
		for(int i=0; i<n*n; ++i)
			cout<<binary[n*n-i-1];
			
		cout<<endl;
*/
		for(int i=0; i<n*n; ++i)
		{
			world[i/n][n-1-(i)%n]=binary[i];
		}
/*		
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
				cout<<world[i][j];
			cout<<endl;
		}
*/
		if(n==0) break;
		cin>>x>>y;
		y=n-y; x--;
//		cout<<x<<" "<<y<<endl;
/*
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
				cout<<world[i][j];
			cout<<endl;
		}
*/
		int dir=0;
		bool flag=false;
		while(true)
		{
			if( y==0 && x==n-1)
			{
				flag=true;
				break;
			}
			if(x<0 || x>=n || y<0 || y>=n)
				break;

			if(world[y][x])
				dir=(dir+1)%4;
			else
				dir=(dir-1)%4;
//			cout<<dir<<endl;
			world[y][x]=!world[y][x];
			if(dir==0)
				--y;
			else if(dir==1 || dir==-3)
				++x;
			else if(dir==2 || dir==-2)
				++y;
			else if(dir==3 || dir==-1)
				--x;
		}
		if(flag) cout<<	"Yes" <<endl;
		else cout<<"Kaputt!"<<endl;

	}

}