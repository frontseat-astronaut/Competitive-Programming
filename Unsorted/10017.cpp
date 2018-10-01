#include<iostream>
#include<vector>
#define int long long
using namespace std;

int N,M;
vector<int>pegs[3];

void hanoi(int p[], int n, int t, int &moves)
{
	if(n==0) return ;
	hanoi(p, n-1, 3-t-p[n], moves);
	if(moves>=M)
		return ;
	pegs[p[n]].pop_back();
	pegs[t].push_back(n);
	p[n]=t;
	moves++;
	
	//printing!
	for(int i=0; i<3; ++i)
	{
		cout<<(char)('A'+i)<<"=>";
		if(pegs[i].size())
		{
			cout<<"  ";
			for(auto d:pegs[i])
				cout<<" "<<d;
		}
		cout<<endl;
	}
	cout<<endl;

	if(moves>=M)
		return;

	hanoi(p, n-1, t, moves);
}

int32_t main()
{
	int caseno=1;
	while(cin>>N>>M)
	{
		if(N==0) break;
		cout<<"Problem #"<<caseno++<<endl<<endl;
		for(int i=0; i<3; ++i)
			pegs[i].clear();
		for(int i=0; i<N; ++i)
			pegs[0].push_back(N-i);
		for(int i=0; i<3; ++i)
    	{
    		cout<<(char)('A'+i)<<"=>";
    		if(pegs[i].size())
    		{
    			cout<<"  ";
    			for(auto d:pegs[i])
    				cout<<" "<<d;
    		}
    		cout<<endl;
    	}
    	cout<<endl;
		int p[N+1]={};
		int moves=0;
		hanoi(p,N,2,moves);
	}
}