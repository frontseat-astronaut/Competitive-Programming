#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	unordered_map <int,int> M;
	for(int i=0; i<n; ++i)
	{
		cin>>a[i];
		M[a[i]]++;
	}

	int k=n;
	for(int i=0; i<n; ++i)
	{
		bool found=false;
		M[a[i]]--;
		for(long long j=2; j<=2000000001; j*=2)
		{
			if(M[(long long)j-a[i]])
			{
				found=true;
				break;
			}
		}
		if(!found)
		{
			k--;
			continue;
		}
		M[a[i]]++;
	}
	cout<<n-k<<endl;
}