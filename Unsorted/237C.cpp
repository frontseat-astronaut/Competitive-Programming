#include<iostream>
using namespace std;

int main()
{
	int a,b,k;
	cin>>a>>b>>k;
	bool iscons[b+2]={0};
	iscons[1]=1	;
	for(int i=2; i*i<=b; ++i)
	{
		if(!iscons[i])
		{
			for(int j=i; j*i<=b; ++j)
				iscons[i*j]=1;
		}
	}
	int l=a, r=a, cnt=0;
	int max=-1;
	while(r<=b)
	{
//		cout<<l<<" "<<r<<" "<<max<<endl; 
		cnt+=(iscons[r]+1)%2;
		if(cnt>=k)
		{
			if(r-l+1>max)
				max=r-l+1;
			cnt-=(iscons[l]+1)%2;
			++l;
		}
		else if (r==b)
		{
			if(max==-1)
				break;
			max=r-l+2;
		}
		++r;
	}
	cout<<max<<endl;
	
}