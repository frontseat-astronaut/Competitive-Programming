#include<iostream>
#include<deque>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;

	deque <int> L;

	for(int i=0; i<n; ++i)
	{
		int var;
		cin>>var;
		L.push_back(var);
	}

	int ans=0;
	while(n)
	{
		if(L.front()<=k)
		{
			L.pop_front();
			++ans;
			n--;
		}
		
		else if(n && L.back()<=k)
		{
			L.pop_back();
			++ans;
			n--;
		}

		else
		{
			break;
		}
	}
	cout<<ans<<endl;
}