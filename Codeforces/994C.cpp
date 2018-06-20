#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

struct point
{
	int x,y;
};

int main()
{
	point p[4],P[4];
	int x1,x2,X1,X2,y1,y2,Y1,Y2;

	for(int i=0; i<4; ++i)
	{
		cin>>p[i].x>>p[i].y;
	}
	for(int i=0; i<4; ++i)
	{
		cin>>P[i].x>>P[i].y;
	}

	int flag=0;
	
	x1=p[0].x, x2=p[0].x,X1=P[0].x,X2=P[0].x,y1=p[0].y,y2=p[0].y,Y1=P[0].y,Y2=P[0].y;
	for(int i=1; i<4; ++i)
	{
		if(x1>p[i].x)
			x1=p[i].x;
		if(x2<p[i].x)
			x2=p[i].x;

		if(y1>p[i].y)
			y1=p[i].y;
		if(y2<p[i].y)
			y2=p[i].y;

		if(X1>P[i].x)
			X1=P[i].x;
		if(X2<P[i].x)
			X2=P[i].x;

		if(Y1>P[i].y)
			Y1=P[i].y;
		if(Y2<P[i].y)
			Y2=P[i].y;
	}

	if(x1>X2 || x2<X1 || y1>Y2 || y2<Y1)
	{
		flag++;
	}

	for(int i=0; i<4; ++i)
	{
		int x=p[i].x;
		int y=p[i].y; 
		p[i].x=x+y;
		p[i].y=-x+y;	
	}
	for(int i=0; i<4; ++i)
	{
		int x=P[i].x;
		int y=P[i].y;
		P[i].x=x+y;
		P[i].y=-x+y;	
	}

//	cout<<flag<<" ";
	x1=p[0].x, x2=p[0].x,X1=P[0].x,X2=P[0].x,y1=p[0].y,y2=p[0].y,Y1=P[0].y,Y2=P[0].y;
	for(int i=1; i<4; ++i)
	{
		if(x1>p[i].x)
			x1=p[i].x;
		if(x2<p[i].x)
			x2=p[i].x;

		if(y1>p[i].y)
			y1=p[i].y;
		if(y2<p[i].y)
			y2=p[i].y;

		if(X1>P[i].x)
			X1=P[i].x;
		if(X2<P[i].x)
			X2=P[i].x;

		if(Y1>P[i].y)
			Y1=P[i].y;
		if(Y2<P[i].y)
			Y2=P[i].y;
	}

	if(x1>X2 || x2<X1 || y1>Y2 || y2<Y1)
	{
		flag++;
	}
//	cout<<flag<<endl;

	if(!flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}