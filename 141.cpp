#include<iostream>
#include<set>
using namespace std;

int main()
{
	int N;
	while(true)
	{
		cin>>N;
	 	if(!N) break;

		set <int> M[2*N];
		set <int> curr[4];

		int player=0, winner=0; 

		for(int i=0; i<2*N; ++i)
		{
			int r,c;
			char ch;
			cin>>r>>c>>ch;

			if(winner)
				continue;

			if(ch=='-')
			{
				curr[0].erase(N*(r-1)+c);
				curr[1].erase(N*(c-1)+N-r+1);
				curr[2].erase(N*(N-r)+N-c+1);
				curr[3].erase(N*(N-c)+r);
			}
			else
			{
				curr[0].insert(N*(r-1)+c);
				curr[1].insert(N*(c-1)+N-r+1);
				curr[2].insert(N*(N-r)+N-c+1);
				curr[3].insert(N*(N-c)+r);
			}

			bool flag=0;
			for(int j=0; j<i; ++j)
			{
				if(M[j].size()!=curr[0].size())
					continue;
				
				for(int k=0; k<4; ++k)
				{
					bool match=1;
					for(auto it:curr[k])
					{
						if( M[j].find(it)==M[j].end() )
						{
							match=0;
							break;
						}
					}
					if(match)
					{
						flag=1;
						break;
					}
				}
				if(flag)
					break;
			}
			if(flag)
			{
				cout<<"Player "<<(player+1)%2+1<<" wins on move "<<i+1<<endl;
				winner=1;
				continue;
			}

			M[i]=curr[0];

			player=(player+1)%2;

		}
		if(!winner)
			cout<<"Draw"<<endl;

	}
}	 