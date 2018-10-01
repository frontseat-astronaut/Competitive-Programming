#include<iostream>
#include<vector>
#include<set>
using namespace std;

int n;
set<char>nodes;
bool adjm[256][256];

struct seq
{
	int band;
	vector<char>arr;
};

seq backtrack(vector<char>arr, set<char>left, int i, int max)
{
	if(i==n)
	{
		return {max, arr};
	}
	int best=n;
	char  ans;
	for(auto l:left)
	{
		int maxm=max;
		for(int j=0; j<i; ++j)
		{
			if(adjm[l][arr[j]])
			{
				if(maxm<i-j)
					maxm=i-j;
				break;
			}
		}
		arr[i]=l;
		set<char>temp;
		temp=left;
		temp.erase(l);
		seq bnext=backtrack(arr,temp,i+1,maxm);
		if(bnext.band<=best)
		{
			best =bnext.band;
			ans=l;
		}
	}
	arr[i]=ans;
	return {best, arr};
}

int main()
{ 
	string G;
	while(1)
	{
		cin>>G;
		if(G=="#")
			break;
		int L=G.length();
		nodes.clear();
		for(int i=0; i<L; ++i)
		{
			nodes.insert(G[i]);
			char ch=G[i];
			i++; i++;
			while(i<L && G[i]!=';')
			{
				adjm[ch][G[i]]=1;
				adjm[G[i]][ch]=1;
				nodes.insert(G[i]);
				++i;
			}
		}
		n=nodes.size();
		set<char>left=nodes;
		vector<char>a;
		seq ans=backtrack(a,left,0,0);
		cout<<ans.arr.size()<<endl;
		for(auto node:ans.arr)
			cout<<node<<" ";
	}
}