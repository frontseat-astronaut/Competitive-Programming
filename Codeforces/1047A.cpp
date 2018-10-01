#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int p[3];
	p[0]=p[1]=p[2]=n/3;
	p[0]+=n-3*(n/3);
	int streak=0;
	if(p[0]%3==0 &&p[1]%3==2)
	{
		cout<<p[0]-2<<' '<<p[1]+2<<' '<<p[2]<<endl;
		return 0;
	}
	int i=0;
	while(streak<3)
	{
		if(p[i]%3==0)
		{
			p[i]--;
			p[(i+1)%3]++;
			streak=0;
		}	
		streak++;
		i=(i+1)%3;
	}
	cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<endl;
}