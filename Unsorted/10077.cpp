#include<iostream>
using namespace std;

struct num
{
	int m,n;
};

int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		if(m==1 && n==1) break;
		num l={0,1}, r={1,0}, mid={1,1};
		string ans="";
		while(1)
		{
			mid={l.m+r.m, l.n+r.n};
			if(mid.m==m && mid.n==n)
			{
				break;
			}
			else if(mid.m*n<mid.n*m)
			{
				l=mid;
				ans+="R";
				continue;
			}
			else
			{
				ans+="L";
				r=mid;
			}
		}
		cout<<ans<<endl;
	}
}