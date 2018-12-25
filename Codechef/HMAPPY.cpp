#include<bits/stdc++.h>
using namespace std;
int MAX=400010;
#define pii pair<int,int>
#define f first
#define s second

int ones(int l, int r, pii ra[], int i, int imod)
{
	return min(ra[imod].f,i-l)+min(ra[imod].s,r+1-i);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int a[MAX];
	int n,k,i,j,Q;
	string q;
	int l, r, maxm=0, t, lmod, rmod, imod;
	map<int,int>m;
	cin>>n>>Q>>k;
	pii ra[n];
	for(i=0; i<n; ++i)
	{
		cin>>a[i];
	}
	while(i<MAX)
	{
		a[i]=a[i%n];
		++i;
	}
	i=n;
	if(a[i])
	{
		while(a[i] && i>=0)
			i--;
		i++;
	}

	j=i;
	i=n;
	while(i<2*n)
	{
//		cout<<i-n<<endl;
		if(!a[i])
		{
			ra[i-n]={0,0};
			++i;
			j=i;
			continue;
		}
		while(a[i] && i<3*n)
			++i;
		for(int l=max(0,j-n); l<min(i-n,n); ++l)
		{
			ra[l]={l-j+n,i-n-l};
		}
		j=i;
	}
	/*
	for (int i = 0; i < n; ++i)
	{
		cout<<ra[i].f<<' '<<ra[i].s<<endl;
	}
	*/
	r=(MAX/n)*n-1, l=r-n+1;
	j=0, i=0;
	while(i<n)
	{
		if(!a[i])
		{
			m[i-j]++;
			m[0]++;
			maxm=max(maxm, i-j);
			j=i+1;
		}
		++i;
	}
	maxm=max(maxm, i-j);
	m[i-j]++;
	cin>>q;
	for(auto ch:q)
	{
		if(ch=='?')
		{
			cout<<min(k, maxm)<<endl;
			continue;
		}
		lmod=l%n, rmod=r%n;
//		cout<<lmod<<' '<<rmod<<endl;
		if(a[l-1])
		{		
			t=ones(l, r, ra, l, lmod);
//			cout<<t<<' ';
			m[t]--;
			if(!m[t])
				m.erase(t);
			t=ones(l-1, r-1, ra, l-1, (lmod-1+n)%n);
//			cout<<t<<' ';
			m[t]++;
		}
		if(a[r])
		{
			t=ones(l, r, ra, r, rmod);
//			cout<<t<<' ';
			m[t]--;
			if(!m[t])
				m.erase(t);
			t=ones(l-1, r-1, ra, r-1, (rmod-1+n)%n);
//			cout<<t<<endl;
			m[t]++;
		}
		maxm=(*m.rbegin()).f;
	
		l--, r--;
	}

}