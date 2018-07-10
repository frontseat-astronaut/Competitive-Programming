#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//undirected graph!
int N;
vector<vector <int>> adj;

void add_node()
{
	vector<int> node;
	adj.push_back(node);
}

int add_edge(int a, int b)
{
	adj[a].push_back(b);
	adj[b].push_back(a);
}

void BFS(int x)
{
	queue <int> q;
	bool visited[N]={0};
	int distance[N];

	visited[x]=true;
	distance[x]=0;
	q.push(x);

	while(q.size())
	{
		int node=q.front(); 
		q.pop();

		cout<<node<<" "<<distance[node]<<endl;

		for(auto anode: adj[node])
		{
			if(visited[anode]) continue;
			q.push(anode);
			distance[anode]=distance[node]+1;
			visited[anode]=1;
		}
	}
}
void DFS(int x, bool visited[])
{
	if(visited[x]) return;
	visited[x]=1;
	cout<<x<<endl;
	for(auto s:adj[x])
		DFS(s,visited);
}

int main()
{
	cin>>N;
	for(int i=0; i<N; ++i)
		add_node();
	int e;
	cin>>e;
	for(int i=0; i<e; ++i)
	{
		int a,b;
		cin>>a>>b;
		add_edge(a,b);
	}
	cout<<endl;
//	BFS(1);
	bool visited[N]={0};
	DFS(0,visited);
}