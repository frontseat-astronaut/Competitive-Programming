#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

pii cntbw(int clr, int n, int m)
{
	int arr[2];
	arr[clr]=n*m-(n*m)/2;
	arr[!clr]=(n*m)>>1;
	return {arr[0], arr[1]};
}

int32_t main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, m;
		cin>>n>>m;

		pii w[2];
		pii b[2];
		pii inter[2];

		cin>>w[0].ff>>w[0].ss>>w[1].ff>>w[1].ss;
		cin>>b[0].ff>>b[0].ss>>b[1].ff>>b[1].ss;

		pii cnt=cntbw(0, n, m), rec1, rec2, rec3;
		bool tmp;

		if(w[0].ff>b[1].ff || w[1].ff<b[0].ff || w[0].ss>b[1].ss || w[1].ss<b[0].ss)
		{
			tmp=(w[0].ff+w[0].ss)&1;
			rec1=cntbw(tmp, w[1].ff-w[0].ff+1, w[1].ss-w[0].ss+1);
			cnt.ff+=rec1.ss;
			cnt.ss-=rec1.ss;

			tmp=(b[0].ff+b[0].ss)&1;
			rec2=cntbw(tmp, b[1].ff-b[0].ff+1, b[1].ss-b[0].ss+1);
			cnt.ss+=rec2.ff;
			cnt.ff-=rec2.ff;
		}
		else
		{
			inter[0].ff=max(b[0].ff, w[0].ff);
			inter[0].ss=max(b[0].ss, w[0].ss);
			inter[1].ff=min(b[1].ff, w[1].ff);
			inter[1].ss=min(b[1].ss, w[1].ss);

			tmp=(w[0].ff+w[0].ss)&1;
			rec1=cntbw(tmp, w[1].ff-w[0].ff+1, w[1].ss-w[0].ss+1);
			cnt.ff+=rec1.ss;
			cnt.ss-=rec1.ss;

			tmp=(b[0].ff+b[0].ss)&1;
			rec2=cntbw(tmp, b[1].ff-b[0].ff+1, b[1].ss-b[0].ss+1);
			cnt.ss+=rec2.ff;
			cnt.ff-=rec2.ff;

			tmp=(inter[0].ff+inter[0].ss)&1;
			rec3=cntbw(tmp, inter[1].ff-inter[0].ff+1, inter[1].ss-inter[0].ss+1);
			cnt.ff-=rec3.ss;
			cnt.ss+=rec3.ss;
		}
		cout<<cnt.ff<<" "<<cnt.ss<<endl;
	}
}