#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
	int n,B;
	cin>>n>>B;

	int a[2*n+1];
	for(int i=1; i<2*n+1; i+=2)
	{
		cin>>a[i];
	}
	vector<int> cuts;
	int c=0, start=0;
//	cout<<0<<" ";
	for(int i=2; i<2*n+1; i+=2)
	{
		if(a[i-1]%2==0)
		{
			c++;
		}
		else
		{
			c--;
		}
		if(c==0 )
		{
			cuts.push_back(fabs(a[i-1]-a[i+1]));
			start=i;
		}
//		cout<<a[i-1]<<" "<<c<<" ";
	}
	cuts.pop_back();
	sort(cuts.begin(), cuts.end());
	int num=0, sum=0;
	for(auto cut:cuts)
	{
		sum+=cut;
		if(sum>B)
			break;
		++num;
	}
	cout<<num<<endl;
}