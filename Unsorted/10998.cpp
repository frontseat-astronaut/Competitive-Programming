#include<iostream>
#include<math.h>
using namespace std;

bool dac(double H, double V, double h, double v, bool clr, double x, double y)
{
	if((x<h*H && y>v*V)||(x>h*H && y<v*V))
		return clr;
	else if(x>h*H && y>v*V)
	{
		return dac((1-h)*H, (1-v)*V, h,v,(clr+1)%2, x-h*H,y-v*V);
	}
	return dac(h*H, v*V, h,v,(clr+1)%2, x,y);
}

int main()
{
	double H, V;
	double h,v;
	int caseno=1;
	while(cin>>H>>V>>h>>v)
	{
		if(fabs(H)<=0.0000000000001) break;
		cout<<"Case "<<caseno++<<":"<<endl;
		int n;
		cin>>n;
		while(n--)
		{
			double x,y;
			cin>>x>>y;
			bool clr=dac(H, V, h,v,1,x,y);
			if(clr) cout<<"black"<<endl;
			else cout<<"white"<<endl;
		}
	}
}