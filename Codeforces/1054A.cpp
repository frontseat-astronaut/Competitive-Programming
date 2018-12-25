#include<bits/stdc++.h>

using namespace std;

int main()
{
	int x, y, z, t1, t2, t3;
	cin>>x>>y>>z>>t1>>t2>>t3;

	int s=fabs(x-y)*t1;
	int e=t2*(fabs(x-y)+fabs(x-z))+3*t3;
	if(s<e)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
}