#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int l, r, d, q;
	cin>>q;
	while(q--)
	{
		cin>>l>>r>>d;
		int lq, rq, lr, rr;
		lq=l/d;
		rq=r/d;
		lr=l%d;
		rr=r%d;
		if(lq>1 )
		{
			cout<<d<<"\n";
			continue;
		}
		if(lq==1)
		{
			if(lr!=0)
			{
				cout<<d<<"\n";
				continue;
			}
		}
		if(rr!=0)
			cout<<(int)ceil((double)r/d)*d<<"\n";
		else
			cout<<r+d<<"\n";
	}

}