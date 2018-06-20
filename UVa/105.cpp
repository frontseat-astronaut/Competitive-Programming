#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct marker 
{
	int x,H;
	int id;
};

bool cmp (marker a, marker b)
{
	return a.x<b.x;
}

int main()
{
	vector<marker>X;
	map<int, int>Y;
	int L,H,R,id=1;
	while(cin>>L)
	{
		cin>>H>>R;

		X.push_back({L,H,id});
		X.push_back({R,H,-id});
		++id;
	}
	sort(X.begin(),X.end(),cmp);
	
	int N=X.size();
	vector <int> S;
	int init_h=0;
	for(int i=0; i<N; )
	{
		int x=X[i].x;
		while(X[i].x==x && i<N)
		{
			if(X[i].id<0)
			{
				Y[X[i].H]--;
				if(Y[X[i].H]==0)
					Y.erase(Y.find(X[i].H));
			}
			else
			{
				Y[X[i].H]++;
			}
			++i;
		}

		if(Y.empty())
		{
			S.push_back(x);
			S.push_back(0);
		}
		else
		{
			auto it=Y.end();
			it--;
			if(init_h!=(*it).first)
			{
				S.push_back(x);
				S.push_back((*it).first);
			}			
		}
		if(!Y.empty())
		{
			auto it=Y.end();
			it--;
			init_h=(*it).first;
		}
		else
		{
			init_h=0;
		}
			
	}

	int SL=S.size();

	for(int i=0; i<SL; ++i)
	{
		if(i==SL-1) cout<<S[i]<<endl;
		else cout<<S[i]<<" ";
	}
}