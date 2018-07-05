#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;

	int a[n], c[m]={0};
	queue <int> lm[m];
	
	for(int i=0; i<n; ++i)
	{
		cin>>a[i];
		++c[a[i]%m];
		lm[a[i]%m].push(i);
	}

	int equal=0;
	for(int i=0; i<m; ++i)
	{
		if(m*c[i]==n)
		{
			++equal;
		}
	}
//	cout<<c[0]<<" "<<c[1]<<endl;
	int r=0; 
	int moves=0;
	while(equal<m)
	{
//		cout<<r<<" "<<c[r];
		while(c[r]>n/m)
		{
			lm[(r+1)%m].push(lm[r].front());
			a[lm[r].front()]++;
			lm[r].pop();

			--c[r];
			if(c[r]==n/m)
			{
				++equal;
			}
			if(c[(r+1)%m]==n/m)
			{
				--equal;
			}
			++c[(r+1)%m];
			if(c[(r+1)%m]==n/m)
			{
				++equal;
			}
			++moves;
		}
//		cout<<" -> "<<c[r]<<" "<<equal<< endl;
		r=(r+1)%m;
	}
	cout<<moves<<endl;
	for(int i=0; i<n; ++i)
		cout<<a[i]<<" ";
	cout<<endl;

}