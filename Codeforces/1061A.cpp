#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, S;
	cin>>n>>S;
	int i=n, cnt=0;
	while(S)
	{
		while(i<=S)
		{
			cnt++;
			S-=i;
		}
		i--;
	}
	cout<<cnt<<endl;
}