#include<iostream>
using namespace std;

float sqrt(float num, float l, float r, int it)
{
	if(it==3)
		return 0;
	float unit=(r-l)/10;
	int i;
	for( i=0; i<10; ++i)
	{
		if((i*unit+l)*(i*unit+l)>num)
		{
			i--;
			break;
		}
	}
	return i*unit+sqrt(num,l+i*unit,l+(i+1)*unit, ++it);
}
int main()
{
	while(true)
	{
		float num;
		cin>>num;
		cout<<sqrt(num,0,num,0)<<endl;
	}
}