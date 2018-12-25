#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
int l, r;
string x;
int L=0, xL;

string extend (string s)
{
	string c;
	int l=s.length();
	if(l>L)
	{
		int i;
		for( i=l-L; i<l;++i)
			c+=s[i];
		return c;
	}
	return s;
}

struct node
{
	node *next[2];
	int jump;
	pii range;
	vector<int>ind;
};
node *nex;
node *root;
unordered_map<int, vector<node*>>pts;

bool insert(string b, int index)
{
	bL=b.length();
	int i=bL-L;
	node *it=root;
	root->range.f=min(index, (*it).range.f);
	root->range.s=max(index, (*it).range.s);

	while(i<0)
	{
		if(it->next[0]!=NULL)
		{
			it=it->next[0];
			i+=it->jump+1;

			(*it).range.f=min(index, (*it).range.f);
			(*it).range.s=max(index, (*it).range.s);
		}
		else
			break;
	}
	if(i<0)
	{
		it->next[0]=new node();
		it=it->next[0];
		it->jump=-i-1;
		pts[1+L-bL].pb(it);
		(*it).range.f=index;
		(*it).range.s=index;
		i=0;
	}

	while(i<bL)
	{
		if(it->next[b[i]-'0']!=NULL)
		{
			it=it->next[b[i++]-'0'];

			(*it).range.f=min(index, (*it).range.f);
			(*it).range.s=max(index, (*it).range.s);
		}
		else
			break;
	}
	while(i<bL)
	{
		it->next[b[i]-'0']=new node();
		it=it->next[b[i]-'0'];
		(*it).range.f=index;
		(*it).range.s=index;
		pts[1+L-bL].pb(it);
		i++;
	}
	it->ind.pb(index);
}

int query(int i, node *it)
{
	if(i==L)
	{
		auto L=lower_bound(it->ind.begin(), it->ind.end(), l);
		auto R=upper_bound(it->ind.begin(), it->ind.end(), r);
		if(L-it->ind.begin()>R-it->ind.begin()-1)
			return 0;
		return *L;	
	}
	bool nbit=x[i]-'0';
	int temp;
	nbit=!nbit;
	if(it->next[nbit]!=NULL)
	{
		nex=it->next[nbit];
		if(!(nex->range.f>r || nex->range.s<l))
		{
			temp=query(i+1, nex);
			if(temp)
			{
				return temp;
			}
		}
	}
	if(it->next[!nbit]!=NULL)
	{
		nex=it->next[!nbit];
		if(!(nex->range.f>r || nex->range.s<l))
		{
			temp=query(i+1, nex);
			if(temp)
			{
				return temp;
			}
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,q;
	cin>>n>>q;
	pair<int,string> b[n];

	root=new node();
	root->range.f=n+1;
	root->range.s=0;
	for(int i=0; i<n; ++i)
	{
		cin>>b[i].s;
		b[i].f=i;
		L=max(L, (int)b[i].s.length());
	}
	sort(b,b+n, cmp);

	for(int i=0; i<n; ++i)
	{
		T.insert(b[i].f, b[i].s);
	}

	while(q--)
	{
		cin>>l>>r>>x;
		x=contract(x);
		xL=x.length();	
		cout<<query(0,root)<<endl;
	}
}