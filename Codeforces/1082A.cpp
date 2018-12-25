#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, x, y, d, ans=INT_MAX;
		cin>>n>>x>>y>>d;

		if((y-x)%d==0)
			ans=min(ans, (int)(fabs(y-x))/d);
		if((y-1)%d==0)
			ans=min(ans, (y-1)/d + (int)ceil((double)(x-1)/d) );
		if((n-y)%d==0)
			ans=min(ans, (n-y)/d + (int)ceil((double)(n-x)/d) );
		if(ans==INT_MAX)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
	}
}