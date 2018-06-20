#include<iostream>
using namespace std;

struct point
{
	int x,y;
};

int main()
{
	int N;
	while(true)
	{
		cin>>N;
		if(N==0) break;
		point P[2*N];

		for(int i=0; i<2*N; ++i)
		{
			cin>>P[i].x>>P[i].y;
		}
		int A=1000,B=1000;

		for(int i=0; i<=500; ++i)
		{
			for(int j=0; j<=500; ++j)
			{
				int count1=0;
				bool flag1=false;
				int count2=0;
				bool flag2=false;
				int count3=0;
				bool flag3=false;
				int count4=0;
				bool flag4=false;
				for(int k=0; k<2*N; ++k)
				{
					if(i*P[k].x+j*P[k].y<0)
						++count1;
					if(i*P[k].x+j*P[k].y==0)
					{
						flag1=true;
					}
					if(i*P[k].x-j*P[k].y<0)
						++count2;
					if(i*P[k].x-j*P[k].y==0)
					{
						flag2=true;
					}
					if(-i*P[k].x+j*P[k].y<0)
						++count3;
					if(-i*P[k].x+j*P[k].y==0)
					{
						flag3=true;
					}
					if(-i*P[k].x-j*P[k].y<0)
						++count4;
					if(-i*P[k].x-j*P[k].y==0)
					{
						flag4=true;
					}
				}
				if(flag1==false && count1==N)
				{
					A=i;
					B=j;
					break;
				}
				if(flag2==false && count2==N)
				{
					A=i;
					B=-j;
					break;
				}
				if(flag3==false && count3==N)
				{
					A=-i;
					B=j;
					break;
				}
				if(flag4==false && count4==N)
				{
					A=-i;
					B=-j;
					break;
				}
			}
			if(A!=1000)
				break;
		}
		cout<<A<<" "<<B<<endl;
	}
}