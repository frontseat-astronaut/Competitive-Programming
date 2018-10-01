#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main()
{
	int N;
	while(cin>>N)
	{
		if(!N) break;
		vector<int>adj[N+1];
		for(int i=1; i<=N; ++i)
		{
			int d;
			cin>>d;
			while(d--)
			{
				int x;
				cin>>x;
				adj[i].push_back(x);
			}
		}
		int max=0, max_i;

		for(int i=N; i>=1; --i)
		{
//			cout<<i<<endl;
			bool visited[N+1]={0};
			visited[i]=1;
			int dep=0;

			queue <int> Q;
			Q.push(i);
			while(Q.size())
			{
				int s=Q.front(); 
				Q.pop();

//				cout<<s<<" ";

				for(auto x: adj[s])
				{
					if(visited[x]) continue;
					visited[x]=1;
					Q.push(x);
					++dep;
				}
			}

			if(max<=dep)
			{
				max=dep;
				max_i=i;
			}
//			cout<<dep<<endl<<endl	;
		}
		cout<<max_i<<endl;
	}
}