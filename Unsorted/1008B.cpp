#include<iostream>
using namespace std;

struct rec
{
	int w,h;
};

int main()
{
	int n;
	cin>>n;

	rec R[n];
	for(int i=0; i<n; ++i)
	{
		int h,w;
		cin>>h>>w;

		R[i]={min(w,h),max(w,h)};
	}

	bool flag=true;
	for(int i=1; i<n; ++i)
	{
		if(R[i].h>R[i-1].h)
		{
			swap(R[i].h, R[i].w);
			if(R[i].h>R[i-1].h)
			{
				flag=false;
				break;
			}
		}
	}
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}