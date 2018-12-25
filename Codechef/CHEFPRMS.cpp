#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>hprimes;
	int n=0;
	for(int i=2; i<=200; ++i)
	{
		int j=2;
		int cnt=0;
		bool flag=1;
		int N=i;
		while(N>1)
		{
			if(N%j==0)
			{
				N/=j;
				if(N%j==0)
				{
					flag=0;
					break;
				}
				cnt++;
			}
			++j;
		}
		if(cnt==2 && flag)
		{
			hprimes.push_back(i);
			++n;
		}
	}
//	cout<<"n:"<<n<<endl;
	int T,N;
	cin>>T;
	while(T--)
	{
		cin>>N;
		if(N==1)
		{
			cout<<"NO"<<endl;
			continue;
		}
		bool flag=0;
		for(int i=0; i<n; ++i)
		{
			for(int j=i; j<n; ++j)
			{
				if(hprimes[i]+hprimes[j]==N)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}