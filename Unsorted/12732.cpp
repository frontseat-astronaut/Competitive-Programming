#include<iostream>
using namespace std;

void dac(int l, int r)
{
	if(l==r)
	{
		cout<<"Answer "<<l;
		cout<<flush;
		return;
	}
	if(r-l+1==2)
	{
		cout<<"Test "<<l<<" "<<r;
		cout<<flush;
		int a, ans;
		cin>>a;
		if(a==1)
			ans=l;
		else
			ans=r;
		cout<<"Answer "<<ans;
		cout<<flush;
		return;
	}
	int N=r-l+1;
	int mid1=l+N/3, mid2=mid1+N/3;
	cout<<"Test";
	int k=0;
	while(k<2*(N/3))
	{
		cout<<" "<<l+k;
		++k;
	}
	cout<<flush;
	int a;
	cin>>a;
	if(a==1)
		dac(l,mid1-1);
	else if (a==-1)
		dac(mid1,mid2-1);
	else
		dac(mid2,r);
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		dac(1, n);
	}
}