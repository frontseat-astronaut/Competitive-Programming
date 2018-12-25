#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define a second 
#define b first 

int cost(pii arr[], int n, int e)
{
	int c=0;
	for (int i = 0; i < n; ++i)
	{
		c+=(((e-arr[i].a)+arr[i].b)%arr[i].b);
	}
	return c;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		pii arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i].a;
		}
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i].b;
		}
		for (int i = 0; i < n; ++i)
		{
			arr[i].a=(arr[i].a%arr[i].b);
		}
		sort(arr, arr+n);

		int high = arr[0].b-1; 
	    int low = 0, mid; 
	    int ans=INT_MAX;
	    	
		cout<<ans<<endl;

	}
}