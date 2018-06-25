#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n;
	cin>>n;

	queue<int>Q[2];
	for(int i=0; i<2*n; ++i)
	{
		int temp;
		cin>>temp;
		Q[0].push(temp);
	}

	bool q=0;
	int swaps=0;
	while(n)
	{
		int x=Q[q].front();
		Q[q].pop();
//		cout<<Q[q].size()<<endl;
		while(Q[q].front()!=x)
		{
			Q[!q].push(Q[q].front());
			Q[q].pop();
			++swaps;
		}
		Q[q].pop();
		while(Q[q].size())
		{
			Q[!q].push(Q[q].front());
			Q[q].pop();
		}
		q=!q;
		n-=1;
//		cout<<Q[q].size()<<endl;
	}
	cout<<swaps<<endl;
}