#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
	int n;
	cin>>n;
	unordered_set<int> S;
	for(int i=0; i<n; ++i)
	{
		int x;
		cin>>x;
		if(x)
			S.insert(x);
	}
	cout<<S.size()<<endl;
}