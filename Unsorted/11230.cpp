#include<iostream>
using namespace std;
int main()
{
	int n, m, r, c;
	while(cin>>n>>m>>r>>c)
	{
		if(n==0) break;
		bool P[n][m], p[n][m]={};
		getchar();
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<m; ++j)
			{
				char ch=getchar();
				P[i][j]=ch-48;
			}
			getchar();
		}
		bool flag=true;
		int ans=0;
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<m; ++j)
			{
				if(P[i][j]!=p[i][j])
				{
					if(m-j<c || n-i<r)
					{
						flag=0;
						break;
					}
					for(int k=0; k<r; ++k)
					{
						for(int l=0; l<c; ++l)
							p[k+i][l+j]=(p[k+i][l+j]+1)%2;
					}
					ans++;
				}
			}
			if(!flag) break;
		}
		if(flag) cout<<ans<<endl;
		else cout<<-1<<endl;
/*		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<m; ++j)
				cout<<p[i][j];
			cout<<endl;
		}
*/	
	}

}