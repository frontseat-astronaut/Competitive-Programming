#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second
#define pb push_back
int l, r;
string x;
int L=0;

bool cmp(pair<int,string>a, pair<int,string>b)
{
	if( a.s.length()!=b.s.length())
		return a.s.length()>b.s.length();
	else
		return lexicographical_compare(b.s.begin(), b.s.end(),a.s.begin(), a.s.end());
}

string extend (string s)
{
	string c;
	int sl=s.length();
	if(sl>L)
	{
		int i;
		for( i=sl-L; i<sl;++i)
			c+=s[i];
		return c;
	}
	for(int i=0; i<L-sl; ++i)
		c+='0';
	c+=s;
	return c;
}
string contract(string s)
{
	string c;
	int sl=s.length();
	int i=0;
	for(auto ch:s)
	{
		if(ch=='1')
		{
			break;
		}
		++i;
	}
	while(i<sl)
	{
		c+=s[i++];
	}
	return c;
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
	int bL=b.length();
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
	assert(i<=0);
	if(i<0)
	{
		it->next[0]=new node();
		it=it->next[0];
		it->jump=-i-1;
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
		it->jump=0;
		(*it).range.f=index;
		(*it).range.s=index;
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
	node *nex;
	int temp;

	if(it->next[!nbit]!=NULL)
	{
		nex=it->next[!nbit];
		if(!(nex->range.f>r || nex->range.s<l))
		{
			temp=query(i+1+nex->jump, nex);
			if(temp)
			{
				return temp;
			}
		}
	}
	if(it->next[nbit]!=NULL)
	{
		nex=it->next[nbit];
		if(!(nex->range.f>r || nex->range.s<l))
		{
			temp=query(i+1+nex->jump, nex);
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
	root->range={n+1,0};
	root->jump=0;
	for(int i=0; i<n; ++i)
	{
		cin>>b[i].s;
		b[i].s=contract(b[i].s);
		b[i].f=i+1;
		L=max(L, (int) b[i].s.length());	
	}

	sort(b, b+n, cmp);

	for(int i=0; i<n; ++i)
	{
		insert(b[i].s,b[i].f);
	}
	while(q--)
	{
		cin>>l>>r>>x;
		x=extend(x);
		int ans=query(0, root);
		cout<<ans<<endl;
	}
}