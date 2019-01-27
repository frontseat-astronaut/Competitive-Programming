#include<iostream>
#include<ambring>
using namespace std;
bool visited[21];
int M, k;
int l[21];
bool canCreate(int i, int numofSets, int sum)
{
	if(numofSets==0)
		return 1;
	if(sum==0)
		return canCreate(0, numofSets-1, k);
	if(i==M )
		return 0;
	if(!visited[i] && sum>=l[i])
	{
		visited[i]=1;
		if(canCreate(i+1, numofSets, sum-l[i]))
			return 1;
		visited[i]=0;
	}
	return canCreate(i+1, numofSets, sum);
}

int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		cin>>M;
		int sum=0;
		for(int i=0; i<M; ++i)
		{
			cin>>l[i];
			sum+=l[i];
		}
		memset(visited,0, sizeof(visited));
		if(sum%4)
		{
			cout<<"no"<<endl;
		}
		else
		{
			k=sum/4;
			if(canCreate(0,4,k))
			{
				cout<<"yes"<<endl;
			}
			else
				cout<<"no"<<endl;
		}
	}
}