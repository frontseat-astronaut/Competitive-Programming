#include<iostream>
#include<vector>
#define int long long
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

int32_t main()
{
	int T;
	cin>>T;
	char g[301][302];
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", g[i]);
		}
		int a[n+1][m+1];
		int d1[n+1][m+1], d2[n+1][m+1];
		vector<pii>house;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				a[i][j]=g[i][j]-'0';
				if(a[i][j])
					house.push_back({i,j});
			}
		int sum;
		for (int i = 0; i < n; ++i)
		{
			sum=0;
			for(int j=0; i-j>=0 && j<m; ++j)
			{
				sum+=a[i-j][j];
				d1[i-j][j]=sum;
			}
		}
		for (int i = 0; i < m; ++i)
		{
			sum=0;
			for(int j=0; i+j<m && n-j-1>=0; ++j)
			{
				sum+=a[n-j-1][i+j];
				d1[n-j-1][i+j]=sum;
			}
		}
		for(int i=0; i<n; ++i)
		{
			sum=0;
			for(int j=0; i+j<n && j<m; ++j)
			{
				sum+=a[i+j][j];
				d2[i+j][j]=sum;
			}
		}
		for (int i = 0; i < m; ++i)
		{
			sum=0;
			for (int j = 0; j<n && i+j<m ; ++j)
			{
				sum+=a[j][i+j];
				d2[j][i+j]=sum;
			}
		}
		int D[n+m-1]={};
		for(auto p: house)
		{
			pii up={p.f-1, p.s}, lef={p.f, p.s-1}, rig, dow;
			int d=1;
			if(p.f-1>=0 && p.s-1>=0)
			{
				while(up.s>=0 && lef.f>=0)
				{
					D[d++]+=d1[up.f][up.s]-d1[lef.f][lef.s]+a[lef.f][lef.s];
					if(up.f==0)
						up.s--;
					else
						up.f--;
					if(lef.s==0)
						lef.f--;
					else
						lef.s--;
				}
				//up
				d=1;
				for(int i=p.f-1; i>=0; --i)
					D[d++]-=a[i][p.s];

				//left
				d=1;
				for(int i=p.s-1; i>=0; --i)
					D[d++]-=a[p.f][i];
			}
			up={p.f-1, p.s}, rig={p.f, p.s+1};
			d=1;
			if(p.f-1>=0 && p.s+1<m)
			{
				while(up.s<m && rig.f>=0)
				{
					D[d++]+=d2[rig.f][rig.s]-d2[up.f][up.s]+a[up.f][up.s];
					if(up.f==0)
						up.s++;
					else
						up.f--;
					if(rig.s==m-1)
						rig.f--;
					else
						rig.s++;
				}

				//up
				d=1;
				for(int i=p.f-1; i>=0; --i)
					D[d++]-=a[i][p.s];
				//right
				d=1;
				for(int i=p.s+1; i<m; ++i)
					D[d++]-=a[p.f][i];

			}
			dow={p.f+1, p.s}, rig={p.f, p.s+1};
			d=1;
			if(p.f+1<n && p.s+1<m)
			{
				while(dow.s<m && rig.f<n)
				{
					D[d++]+=d1[rig.f][rig.s]-d1[dow.f][dow.s]+a[dow.f][dow.s];
					if(dow.f==n-1)
						dow.s++;
					else
						dow.f++;
					if(rig.s==m-1)
						rig.f++;
					else
						rig.s++;
				}

				//down
				d=1;
				for(int i=p.f+1; i<n; ++i)
					D[d++]-=a[i][p.s];

				//right
				d=1;
				for(int i=p.s+1; i<m; ++i)
					D[d++]-=a[p.f][i];

			}
			dow={p.f+1, p.s}, lef={p.f, p.s-1};
			d=1;
			if(p.f+1<n && p.s-1>=0)
			{
				while(dow.s>=0 && lef.f<n)
				{
					D[d++]+=d2[dow.f][dow.s]-d2[lef.f][lef.s]+a[lef.f][lef.s];
					if(dow.f==n-1)
						dow.s--;
					else
						dow.f++;
					if(lef.s==0)
						lef.f++;
					else
						lef.s--;
				}
				//left
				d=1;
				for(int i=p.s-1; i>=0; --i)
					D[d++]-=a[p.f][i];
				//down
				d=1;
				for(int i=p.f+1; i<n; ++i)
					D[d++]-=a[i][p.s];
			}
			//up
			d=1;
			for(int i=p.f-1; i>=0; --i)
				D[d++]+=a[i][p.s];
			//right
			d=1;
			for(int i=p.s+1; i<m; ++i)
				D[d++]+=a[p.f][i];
			//left
			d=1;
			for(int i=p.s-1; i>=0; --i)
				D[d++]+=a[p.f][i];
			//down
			d=1;
			for(int i=p.f+1; i<n; ++i)
				D[d++]+=a[i][p.s];
		}
		for(int d=1; d<=n+m-2; ++d)
			cout<<D[d]/2<<' ';
		cout<<endl;
	}
}