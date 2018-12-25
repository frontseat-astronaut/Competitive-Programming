#include<iostream>
#include<assert.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(NULL);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m,d,D;
		cin>>n>>m>>d>>D;
		if(m<n*d || m>n*D)
		{
			cout<<-1<<"\n";
			continue;
		}
		int diff=0;
		while(m>0)
		{
			int i=0;
			while(m>0 && i<n)
			{
				cout<<i+1<<' '<<(i+diff)%n+1<<endl;
				m--;
				i++;
			}
			diff++;
		}
	}
}