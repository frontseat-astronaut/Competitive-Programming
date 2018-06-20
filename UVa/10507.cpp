#include<iostream>
using namespace std;

int main()
{
	int N,M;
	
	while(cin>>N)
	{
		cin>>M;

		bool state[2][256]={};
		bool brain[256][256] ={};
		
		char a,b;
		cin>>a; state[0][a]=1;
		cin>>a; state[0][a]=1;
		cin>>a; state[0][a]=1;
		for(int i=0; i<M; ++i)
		{
			cin>>a>>b;
			brain[a][b]=1;
			brain[b][a]=1;
		}

		int awake=3, time=0, count;
		bool s=0;
		while(awake>=3 && awake<N)
		{
			int temp=awake;
			for(char i='A'; i<='Z'; ++i)
			{
				if(state[s][i])
				{
					state[s+1][i]=1;
					continue;
				} 
				count=0;
				for(char j='A'; j<='Z';++j)
				{
					if(state[s][j] && brain[i][j]) ++count;
					if(count==3) break;
				}
				if(count==3)
				{
					++awake;
					state[s+1][i]=1;
				} 
				else state[s+1][i]=0;
			}
			if(temp==awake) break;
			time++;
			s=~s;
//			cout<<time<<" "<<endl;
		}
		if(awake>=N) cout<<"WAKE UP IN, "<<time<<", YEARS"<<endl;
		else cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
	}
}
