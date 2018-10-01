#include<iostream>
#include<math.h>
#define int long long
#define pii pair<int,int>
#define x first
#define y second
using namespace std;

int dist(pii A, pii B)
{
	return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
}

bool dogreet(pii A1, pii A2, pii B1, pii B2, int d1)
{
	int Kx=(A2.x-A1.x) - (B2.x-B1.x);
	int Ky=(A2.y-A1.y) - (B2.y-B1.y);

	if(Kx==Ky && !Kx)
	{
		return 0;
	}

	double t0=(double)((A1.x-B1.x)*Kx+Ky*(A1.y-B1.y))/(Kx*Kx+Ky*Ky);
	t0*=-1;
	if(t0<0 || t0>1)
	{
		return (dist(A2,B2)<=d1);
	}
	double min_D=(t0*Kx+(A1.x-B1.x))*(t0*Kx+(A1.x-B1.x))+(t0*Ky+(A1.y-B1.y))*(t0*Ky+(A1.y-B1.y));
	return (min_D-d1)<=0.0000001;
}

int32_t main()
{
	int N, d1, d2, D;
	bool greet=1;
	int ans=0;
	cin>>N>>d1>>d2;
	d1*=d1, d2*=d2;

	pii A[N], B[N];
	for (int i = 0; i < N; ++i)
	{
		cin>>A[i].x>>A[i].y>>B[i].x>>B[i].y;
	}

	if(dist(A[0], B[0])<=d1)
	{
		greet=0;
		ans++;
	}
	for(int i=1; i<N; ++i)
	{
		D=dist(A[i],B[i]);
		if(!greet)
		{
			if(D>d2)
			{
				greet=1;
			}
			continue;
		}
		if(dogreet(A[i-1],A[i],B[i-1],B[i],d1 ))
		{
			greet=0;
			ans++;
		}
		if(D>d2)
			greet=1;
	}
	cout<<ans<<endl;
}