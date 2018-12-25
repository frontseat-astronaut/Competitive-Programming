#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ff  first
#define ss second
using namespace std;

int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int d;
		cin>>d;

		if(d*d-4*d<0)
		{
			cout<<"N"<<endl;
			continue;
		}
		double D=sqrt(d*d-4*d);
		double a=(d+D)*0.5;
		double b=(d-D)*0.5;
		if(fabs(d-D)<-0.0000001)
		{
			cout<<"N"<<endl;
			continue;
		}
		cout<<"Y ";
		printf("%.10lf %.10lf\n",a, b );
	}
}