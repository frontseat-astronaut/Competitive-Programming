#include<iostream>
using namespace std;

unsigned long long d_2=2250000000000;

struct V
{
	long long x,y;
};

unsigned long long r(V v)
{
	return v.x*v.x+v.y*v.y;
}

int main()
{
	int n;
	cin>>n;
	V v[n];
	for(int i=0; i<n; ++i)
	{
		cin>>v[i].x>>v[i].y;
	}

	int c[n];
	V pos={0,0};
	unsigned long long p=0;
	for(int i=0; i<n; ++i)
	{
		unsigned long long d1=r({pos.x+v[i].x, pos.y+v[i].y});
		unsigned long long d2=r({pos.x-v[i].x, pos.y-v[i].y});
		if(d1<=d2)
		{
			c[i]=1;
			pos.x=pos.x+v[i].x;
			pos.y=pos.y+v[i].y;
		}
		else 
		{
			c[i]=-1;
			pos.x=pos.x-v[i].x;
			pos.y=pos.y-v[i].y;
		}
		p=r(pos);
		int j=0;
		while(p>d_2 && j<i)
		{
			unsigned long long dj=r({pos.x-2*c[j]*v[j].x,pos.y-2*c[j]*v[j].y});
			if(dj<p)
			{
				pos={pos.x-2*c[j]*v[j].x,pos.y-2*c[j]*v[j].y};
				p=dj;
				c[j]*=-1;
			}
			++j;
		}
	}
	for(int i=0; i<n; ++i)
		cout<<c[i]<<" ";
	cout<<endl;
//	cout<<(bool)(r(pos)<d_2)<<endl;
}