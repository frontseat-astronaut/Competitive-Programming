#include<iostream>
#include<vector>
using namespace std;

struct node
{
	int p;
	vector<int>c;
	int m;
	int cnt, mcnt;
};

int ans;

int CNT(int i, node V[])
{
	V[i].cnt=1;
	for(auto x: V[i].c)
	{
		V[i].cnt+=CNT(x,V);
	}
	return V[i].cnt;
}
int MCNT(int i, node V[])
{
	V[i].mcnt=V[i].m;
	for(auto x: V[i].c)
	{
		V[i].mcnt+=MCNT(x,V);
	}
	return V[i].mcnt;
}

void f(int i, node V[])
{
	for(auto x: V[i].c)
	{
		if(V[x].mcnt>=V[x].cnt)
		{
			f(x,V);
		}
		else continue;
//		if(!V[x].m) cout<<x+1<<endl;
		int temp=max(0, V[x].m-1);
		V[i].m+=temp;
		V[x].m-=temp;
		V[x].mcnt-=temp;
		ans+=temp;
	}
	for(auto x: V[i].c)
	{
		if(V[x].mcnt<V[x].cnt)
		{
			int temp=V[x].cnt-V[x].mcnt;
			V[x].m+=temp;
			V[x].mcnt+=temp;
			V[i].m-=temp;
			ans+=temp;
			f(x,V);
		}
	}
}

int main()
{
	int n;
	while(cin>>n)
	{
		if(!n) break;
		ans=0;
		node V[n];
		for(int i=0; i<n; ++i)
		{
			int v, N, d;
			cin>>v>>N>>d;
			V[v-1].m=N;
			for(int j=0; j<d; ++j)
			{
				int x;
				cin>>x;
				V[v-1].c.push_back(x-1);
				V[x-1].p=v-1;
			}
		}
		int root, maxm=0;
		for(int i=0; i<n; ++i)
		{
			int cnt=CNT(i, V);
			if(cnt>=maxm)
			{
				root=i;
				maxm=cnt;
			}
		}
		MCNT(root, V);
//		for(int j=0; j<n; ++j)
//			cout<<"["<<j+1<<"]"<<V[j].mcnt<<" "<<V[j].cnt<<" ";
//		cout<<endl;
		f(root,V);
		cout<<ans<<endl;
//		cout<<root<<endl;
	}
}