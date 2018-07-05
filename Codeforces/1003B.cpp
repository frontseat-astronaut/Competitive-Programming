#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int a, b, x;
	cin>>a>>b>>x;
	int k=0, j=0;
	if(a>b)
	{
		for(int i=1; i<=a-ceil((float)(x+1)/2)+1; ++i, ++k)
			cout<<0;
		for(int i=1; i<=b-(x+1)/2+1; ++i, ++k)
			cout<<1;
		
		while(k<a+b)
		{
			int num= (j%2==0)?0:1;
			cout<<num;
			++j;
			++k;
		}
		cout<<endl;
	}
	else
	{
		for(int i=1; i<=b-ceil((float)(x+1)/2)+1; ++i, ++k)
			cout<<1;
		for(int i=1; i<=a-(x+1)/2+1; ++i, ++k)
			cout<<0;
		
		while(k<a+b)
		{
			int num= (j%2==0)?1:0;
			cout<<num;
			++j;
			++k;
		}
		cout<<endl;
	}
	

}