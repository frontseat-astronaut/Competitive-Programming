#include<bits/stdc++.h>
using namespace std;
string a;
int L;
int tree[3000000]={};
void maketree(int &i, int x)
{
	i++;
	tree[x]=1;
	if(a[i]=='(')
	{
		maketree(i, x*2);
	}
	if(a[i]==',')
	{
		i++;
	}
	if(a[i]=='(')
	{
		maketree(i, x*2+1);
	}
	i++;
}
void nametree(int x)
{
	if(!tree[x]) return;
	nametree(2*x);
	if(tree[2*x])
	{
		int temp=2*x;
		while(tree[temp*2+1])
			temp=temp*2+1;
		tree[x]=tree[temp]+1;
	}
	else
	{
		int temp=x;
		while(temp%2==0)
			temp/=2;
		tree[x]=tree[temp/2]+1;
	}
	nametree(2*x+1);
}
void printtree(int x)
{
	if(!tree[x])
		return;
	if(x==1)
		cout<<tree[x];
	else cout<<' '<<tree[x];
	printtree(x*2);
	printtree(x*2+1);
}

int main()
{
	while(1)
	{
		cin>>a;
		if(a=="()")
			break;
		fill( tree, tree + sizeof( tree )/4, 0 );
		L=a.length();	
		maketree(i,1);
		nametree(1);
		printtree(1);
		cout<<endl;
	}
}
