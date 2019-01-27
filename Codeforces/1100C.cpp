#include<bits/stdc++.h>
using namespace std;
double pi=3.1415926535;
int main()
{
	int n;
	double R;
	cin>>n>>R;
	double tn=sin((double)pi/n);
	double r=R*tn/(1-tn);
	printf("%.6f\n", r);
}